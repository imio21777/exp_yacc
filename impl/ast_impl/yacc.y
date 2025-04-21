%code requires {
    #include <memory>
    #include <vector>
    #include <string>
    #include "ast.h" // Include AST node definitions
}

%code provides {
    // Declare the root of the AST (must match main.cpp)
    extern std::unique_ptr<BaseAST> root;
}

%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // For strcpy

// External declaration for the lexer function
extern int yylex();
extern FILE *yyin;

// Error handling function required by Yacc/Bison
void yyerror(const char *s);
%}

%union {
    BaseAST* ast_ptr;    // Pointer to an AST node
    int      int_val;    // Integer literal value
    char*    str_val;    // Identifier or String literal value
    // Using ast_ptr for lists now, actions will handle vector creation/management
}

/* Token Declarations with types */
%token <str_val> IDENT STR_CONST
%token <int_val> INT_CONST
%token MAIN CONST INT BREAK CONTINUE IF ELSE VOID WHILE GETINT PRINTF RETURN NOT AND OR PLUS MINU MULT DIV MOD LSS LEQ GRE GEQ EQL NEQ ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE

%start Program /* Define Program as the start symbol */

/* Non-terminal Types - Primarily using ast_ptr */
%type <ast_ptr> Program CompUnit OptionalTopLevelItems TopLevelItem Decl ConstDecl VarDecl ConstDefList ConstDef ArraySpecifierOpt ConstInitVal ConstInitValList VarDefList VarDef InitVal InitValList FuncDef OptionalFuncFParams FuncParams FuncFParam MainFuncDef Block BlockItemList BlockItem Stmt OptionalExp OptionalPrintfArgs PrintfArgsList Exp Cond LVal LValArrayOpt PrimaryExp Number UnaryExp OptionalFuncRParams FuncRParamsList UnaryOp MulExp AddExp RelExp EqExp LAndExp LOrExp ConstExp

/* Operator Precedence and Associativity */
%right ASSIGN
%left OR
%left AND
%left EQL NEQ
%left LSS LEQ GRE GEQ
%left PLUS MINU
%left MULT DIV MOD
%right NOT /* Unary operators often have higher precedence */
%nonassoc LOWER_THAN_ELSE /* Precedence level for dangling else */
%nonassoc ELSE /* Dangling else */


%%

/* Grammar Rules with Semantic Actions for AST construction (Attempt 3 - Matching ast_example) */

Program
    : CompUnit { root.reset($1); }
    ;

CompUnit /* Optional Declarations/Functions followed by Main Function */
    : OptionalTopLevelItems MainFuncDef
      {
          auto node = new CompUnitAST();
          // This structure needs review based on how OptionalTopLevelItems returns data.
          // If $1 returns a list container node:
          // node->decl_defs = std::move(static_cast<TopLevelListAST*>($1)->items);
          // delete $1;
          // If $1 returns just the last Decl/FuncDef (current simplistic approach):
          if ($1) node->decl.reset($1); // Placeholder, needs proper list aggregation
          node->main_func_def.reset($2);
          $$ = node;
      }
    ;

OptionalTopLevelItems // Returns last item or nullptr. Needs real list aggregation.
    : /* epsilon */ { $$ = nullptr; } 
    | OptionalTopLevelItems TopLevelItem { delete $1; $$ = $2; /* Incorrect: Loses previous items */ }
    ;

TopLevelItem /* Represents one global declaration or non-main function definition */
    : Decl    { $$ = $1; }
    | FuncDef { $$ = $1; }
    ;

Decl /* ConstDecl | VarDecl */
    // This doesn't match ast_example/ast.h (DeclAST has kind and sub-node)
    // Adapting to ast_example/ast.h structure:
    : ConstDecl SEMICN 
      { 
          auto node = new DeclAST();
          node->kind = DeclAST::CONST_DECL;
          node->decl.reset($1);
          $$ = node;
      }
    | VarDecl SEMICN   
      { 
          auto node = new DeclAST();
          node->kind = DeclAST::VAR_DECL;
          node->decl.reset($1);
          $$ = node;
      }
    ;

ConstDecl /* 'const' BType ConstDef { ',' ConstDef } ';' */
    : CONST INT ConstDefList
      {
          // Assuming ConstDeclAST needs to be created here, holding multiple ConstDefs
          // This needs a proper list handling for ConstDefList ($3)
          auto node = new ConstDeclListAST(); // Assuming this exists
          // node->items = ... // Populate from $3
          $$ = node; // Placeholder - returns list node
      }
    ;

ConstDefList // Returns last ConstDef, needs proper list handling
    : ConstDef { $$ = $1; }
    | ConstDefList COMMA ConstDef { delete $1; $$ = $3; /* Incorrect */ }
    ;
    
ConstDef /* Ident [ '[' ConstExp ']' ] '=' ConstInitVal */
    : IDENT ArraySpecifierOpt ASSIGN ConstInitVal
      {
          // Assuming ConstDefAST exists and takes ident, array spec, initval
          auto node = new ConstDefAST($1); 
          // if ($2) node->array_specifier.reset($2);
          // node->value.reset($4);
          free($1);
          $$ = node;
      }
    ;

ArraySpecifierOpt /* [ '[' ConstExp ']' ] */
    : /* epsilon */ { $$ = nullptr; } 
    | LBRACK ConstExp RBRACK { $$ = $2; } // Pass ConstExp AST up
    ;

ConstInitVal /* ConstExp | '{' [ ConstInitVal { ',' ConstInitVal } ] '}' */
    : ConstExp { $$ = $1; } 
    | LBRACE RBRACE { $$ = nullptr; /* TODO: Needs InitListAST? */ }
    | LBRACE ConstInitValList RBRACE { $$ = $2; /* Incorrect list */ }
    ;

ConstInitValList // Returns last item, needs list handling
    : ConstInitVal { $$ = $1; }
    | ConstInitValList COMMA ConstInitVal { delete $1; $$ = $3; /* Incorrect */ }
    ;

VarDecl /* BType VarDef { ',' VarDef } ';' */
    : INT VarDefList
      {
          // Assuming VarDeclAST holds multiple VarDefs
          auto node = new VarDeclListAST(); // Assuming this exists
          // node->items = ... // Populate from $2
          $$ = node; // Placeholder
      }
    ;

VarDefList // Returns last item, needs list handling
    : VarDef { $$ = $1; }
    | VarDefList COMMA VarDef { delete $1; $$ = $3; /* Incorrect */ }
    ;

VarDef /* Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal */
    : IDENT ArraySpecifierOpt 
      {
          // Assuming VarDefAST exists 
          auto node = new VarDefAST($1);
          // if ($2) node->array_specifier.reset($2);
          free($1);
          $$ = node;
      }
    | IDENT ArraySpecifierOpt ASSIGN InitVal 
      {
          auto node = new VarDefAST($1);
          // if ($2) node->array_specifier.reset($2);
          // node->initializer.reset($4); 
          free($1);
          $$ = node;
      }
    ;

InitVal /* Exp | '{' [ InitVal { ',' InitVal } ] '}' */
    : Exp { $$ = $1; } 
    | LBRACE RBRACE { $$ = nullptr; /* TODO: Needs InitListAST? */ }
    | LBRACE InitValList RBRACE { $$ = $2; /* Incorrect list */ }
    ;

InitValList // Returns last item, needs list handling
    : InitVal { $$ = $1; } 
    | InitValList COMMA InitVal { delete $1; $$ = $3; /* Incorrect */ } 
    ;

FuncDef /* Handles INT/VOID directly, EXCLUDES main */
    : VOID IDENT LPARENT OptionalFuncFParams RPARENT Block 
      {
          auto node = new FuncDefAST(TYPE_VOID, $2);
          // node->params = ... // Populate from $4 (list)
          node->block.reset($6);
          free($2);
          $$ = node;
      }
    | INT  IDENT LPARENT OptionalFuncFParams RPARENT Block 
      {
          auto node = new FuncDefAST(TYPE_INT, $2);
          // node->params = ... // Populate from $4 (list)
          node->block.reset($6);
          free($2);
          $$ = node;
      }
    ;

/* FuncType rule is removed */

OptionalFuncFParams // Returns last param, needs list handling
    : /* epsilon */ { $$ = nullptr; } 
    | FuncParams { $$ = $1; /* Incorrect */ }
    ;

FuncParams // Returns last param, needs list handling
    : FuncFParam { $$ = $1; } 
    | FuncParams COMMA FuncFParam { delete $1; $$ = $3; /* Incorrect */ }
    ;

FuncFParam /* BType Ident */
    : INT IDENT 
      {
          auto node = new FuncParamAST(TYPE_INT, $2);
          free($2);
          $$ = node;
      }
    ;

MainFuncDef /* 'int' 'main' '(' ')' Block */
    : INT MAIN LPARENT RPARENT Block 
      {
          auto node = new MainFuncDefAST();
          node->block.reset($5);
          $$ = node;
      }
    ;

Block /* '{' { BlockItem } '}' */
    : LBRACE BlockItemList RBRACE 
      {
          auto node = new BlockAST();
          // node->items = ... // Populate from $2 (list)
          $$ = node; 
      }
    ;

BlockItemList // Returns last item, needs list handling
    : /* epsilon */ { $$ = nullptr; }
    | BlockItemList BlockItem { delete $1; $$ = $2; /* Incorrect */ }
    ;

BlockItem /* Decl | Stmt */
    : Decl { $$ = $1; }
    | Stmt { $$ = $1; }
    ;

Stmt
    : LVal ASSIGN Exp SEMICN 
      { 
          // Assume StmtAST has kind, and maybe specific fields or sub-nodes
          auto node = new StmtAST(); node->kind = StmtAST::ASSIGNMENT;
          // Need specific AssignStmtAST or store lval/exp in StmtAST
          // node->lval.reset($1); node->exp.reset($3); 
          $$ = node; 
      }
    | OptionalExp SEMICN 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::EXP_STMT;
          // if ($1) node->exp.reset($1); 
          $$ = node; 
      }
    | Block 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::BLOCK_STMT;
          // node->block.reset($1);
          $$ = node;
      }
    | IF LPARENT Cond RPARENT Stmt %prec LOWER_THAN_ELSE 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::IF_STMT;
          // node->cond.reset($3); node->then_stmt.reset($5);
          $$ = node;
      }
    | IF LPARENT Cond RPARENT Stmt ELSE Stmt 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::IF_ELSE_STMT;
          // node->cond.reset($3); node->then_stmt.reset($5); node->else_stmt.reset($7);
          $$ = node;
      }
    | WHILE LPARENT Cond RPARENT Stmt 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::WHILE_STMT;
          // node->cond.reset($3); node->body.reset($5);
          $$ = node;
      }
    | BREAK SEMICN 
      { auto node = new StmtAST(); node->kind = StmtAST::BREAK_STMT; $$ = node; }
    | CONTINUE SEMICN 
      { auto node = new StmtAST(); node->kind = StmtAST::CONTINUE_STMT; $$ = node; }
    | RETURN OptionalExp SEMICN 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::RETURN_STMT;
          // if ($2) node->return_exp.reset($2);
          $$ = node;
      }
    | LVal ASSIGN GETINT LPARENT RPARENT SEMICN 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::ASSIGN_GETINT_STMT;
          // node->lval.reset($1); 
          $$ = node; 
      }
    | PRINTF LPARENT STR_CONST OptionalPrintfArgs RPARENT SEMICN 
      { 
          auto node = new StmtAST(); node->kind = StmtAST::PRINTF_STMT;
          // node->format_string = $3; // Need to handle string copy/ownership
          // node->args = ... // Populate from $4 (list)
          free($3); 
          $$ = node; 
      }
    ;

OptionalExp /* [Exp] */
    : /* epsilon */ { $$ = nullptr; }
    | Exp { $$ = $1; }
    ;

OptionalPrintfArgs // Returns last arg, needs list handling
    : /* epsilon */ { $$ = nullptr; }
    | PrintfArgsList { $$ = $1; /* Incorrect */ }
    ;

PrintfArgsList // Returns last arg, needs list handling
    : COMMA Exp { $$ = $2; }
    | PrintfArgsList COMMA Exp { delete $1; $$ = $3; /* Incorrect */ }
    ;

Exp     : AddExp { $$ = $1; } ;
Cond    : LOrExp { $$ = $1; } ;

LVal    /* Ident ['[' Exp ']'] */
    : IDENT LValArrayOpt 
      { 
          // Assuming LValAST exists
          auto node = new LValAST($1); 
          // if ($2) node->array_index.reset($2); 
          free($1); 
          $$ = node; 
      }
    ;
LValArrayOpt /* ['[' Exp ']'] */
    : /* epsilon */ { $$ = nullptr; }
    | LBRACK Exp RBRACK { $$ = $2; }
    ;

PrimaryExp  
    : LPARENT Exp RPARENT { $$ = $2; } 
    | LVal { $$ = $1; }
    | Number { $$ = $1; }
    ;
Number  
    : INT_CONST { $$ = new NumberAST($1); }
    ;

UnaryExp
    : PrimaryExp { $$ = $1; }
    | IDENT LPARENT OptionalFuncRParams RPARENT /* Function Call */
      { 
          // Assuming FuncCallAST exists
          auto node = new FuncCallAST($1); 
          // node->args = ... // Populate from $3 (list)
          free($1); 
          $$ = node; 
      }
    | UnaryOp UnaryExp 
      { 
          // Assuming UnaryExpAST exists
          auto node = new UnaryExpAST(); 
          // node->op = ... // Get op from $1
          // node->operand.reset($2); 
          delete $1; // Delete temporary UnaryOp node
          $$ = node; 
      }
    ;

OptionalFuncRParams // Returns last arg, needs list handling
    : /* epsilon */ { $$ = nullptr; }
    | FuncRParamsList { $$ = $1; /* Incorrect */ }
    ;

FuncRParamsList // Returns last arg, needs list handling
    : Exp { $$ = $1; } 
    | FuncRParamsList COMMA Exp { delete $1; $$ = $3; /* Incorrect */ }
    ;

UnaryOp // Returns temporary node holding op type (adjust if ast.h does differently)
    : PLUS { auto node = new UnaryOpAST(OP_PLUS); $$ = node; }
    | MINU { auto node = new UnaryOpAST(OP_MINUS); $$ = node; }
    | NOT  { auto node = new UnaryOpAST(OP_NOT); $$ = node; }
    ;

/* Standard Expression Hierarchy Rules (Binary Ops) */
MulExp  
    : UnaryExp { $$ = $1; }
    | MulExp MULT UnaryExp { auto node = new BinaryExpAST(OP_MULT); node->left.reset($1); node->right.reset($3); $$ = node; }
    | MulExp DIV UnaryExp  { auto node = new BinaryExpAST(OP_DIV);  node->left.reset($1); node->right.reset($3); $$ = node; }
    | MulExp MOD UnaryExp  { auto node = new BinaryExpAST(OP_MOD);  node->left.reset($1); node->right.reset($3); $$ = node; }
    ;
AddExp  
    : MulExp { $$ = $1; }
    | AddExp PLUS MulExp { auto node = new BinaryExpAST(OP_PLUS); node->left.reset($1); node->right.reset($3); $$ = node; }
    | AddExp MINU MulExp { auto node = new BinaryExpAST(OP_MINUS); node->left.reset($1); node->right.reset($3); $$ = node; }
    ;
RelExp  
    : AddExp { $$ = $1; }
    | RelExp LSS AddExp { auto node = new BinaryExpAST(OP_LSS); node->left.reset($1); node->right.reset($3); $$ = node; }
    | RelExp GRE AddExp { auto node = new BinaryExpAST(OP_GRE); node->left.reset($1); node->right.reset($3); $$ = node; }
    | RelExp LEQ AddExp { auto node = new BinaryExpAST(OP_LEQ); node->left.reset($1); node->right.reset($3); $$ = node; }
    | RelExp GEQ AddExp { auto node = new BinaryExpAST(OP_GEQ); node->left.reset($1); node->right.reset($3); $$ = node; }
    ;
EqExp   
    : RelExp { $$ = $1; }
    | EqExp EQL RelExp { auto node = new BinaryExpAST(OP_EQL); node->left.reset($1); node->right.reset($3); $$ = node; }
    | EqExp NEQ RelExp { auto node = new BinaryExpAST(OP_NEQ); node->left.reset($1); node->right.reset($3); $$ = node; }
    ;
LAndExp 
    : EqExp { $$ = $1; }
    | LAndExp AND EqExp { auto node = new BinaryExpAST(OP_AND); node->left.reset($1); node->right.reset($3); $$ = node; }
    ;
LOrExp  
    : LAndExp { $$ = $1; }
    | LOrExp OR LAndExp { auto node = new BinaryExpAST(OP_OR); node->left.reset($1); node->right.reset($3); $$ = node; }
    ;

ConstExp 
    : AddExp { $$ = $1; } 
    ;


%% 

/* User Code Section */
#include <stdio.h>
#include <iostream> // Needed for unique_ptr declaration if not included by %code requires

// Define the global root pointer (must match declaration in %code provides)
std::unique_ptr<BaseAST> root;

extern char *yytext;
// extern int yylex(); // Already declared above

void yyerror(const char *s) {
    // Bison expects this function to be defined.
    // yytext might not point to the exact error location due to lookahead.
    fprintf(stderr, "Syntax error: %s near '%s'\n", s, yytext ? yytext : "<unknown>");
    // Consider adding line number tracking in lexer for better errors
    exit(1);
}

// Main function is in main.cpp, no need for one here 