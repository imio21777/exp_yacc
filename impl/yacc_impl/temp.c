%{
#define YYDEBUG 0 // Set to 1 for debug traces if needed
#include <stdio.h>
#include <stdlib.h>

// External declarations
extern int yylex();
extern int yylineno;
extern char *yytext;
void yyerror(const char *s);

%}

// Token declarations from lex.l
%token MAIN CONST INT BREAK CONTINUE IF ELSE WHILE GETINT PRINTF RETURN VOID
%token IDENT INT_CONST STR_CONST // Assuming STR_CONST for FormatString
%token ASSIGN LBRACE RBRACE LPARENT RPARENT LBRACK RBRACK SEMICN COMMA
%token NOT AND OR PLUS MINU MULT DIV MOD LSS LEQ GRE GEQ EQL NEQ

// Operator precedence and associativity (Lowest to Highest)
%nonassoc LOWER_THAN_ELSE // For dangling else resolution
%nonassoc ELSE            // For dangling else resolution

%left OR
%left AND
%left EQL NEQ
%left LSS LEQ GRE GEQ
%left PLUS MINU
%left MULT DIV MOD
%right NOT UMINUS // UMINUS for unary minus precedence

// Define start symbol
%start CompUnit

%%

/* Grammar Rules strictly based on SysY specification with conflict resolution */

CompUnit
    : DeclList FuncDefList MainFuncDef { printf("<CompUnit>\n"); }
    ;

DeclList
    : DeclList Decl
    | /* empty */       // Represents {Decl} zero times
    ;

FuncDefList
    : FuncDefList FuncDef
    | /* empty */       // Represents {FuncDef} zero times
    ;

Decl
    : ConstDecl
    | VarDecl
    ;

ConstDecl
    : CONST BType ConstDefList SEMICN { printf("<ConstDecl>\n"); }
    ;

ConstDefList
    : ConstDef
    | ConstDefList COMMA ConstDef // Represents { ',' ConstDef }
    ;

BType : INT ;

ConstDef
    : IDENT ConstArraySpecOpt ASSIGN ConstInitVal
    ;

ConstArraySpecOpt
    : LBRACK ConstExp RBRACK
    | /* empty */       // Represents optional [ '[' ConstExp ']' ]
    ;

ConstInitVal
    : ConstExp
    | LBRACE ConstInitValListOpt RBRACE
    ;

ConstInitValListOpt
    : ConstInitValList
    | /* empty */       // Represents optional [ ConstInitVal { ',' ConstInitVal } ]
    ;

ConstInitValList
    : ConstInitVal
    | ConstInitValList COMMA ConstInitVal // Represents { ',' ConstInitVal }
    ;

VarDecl
    : BType VarDefList SEMICN { printf("<VarDecl>\n"); }
    ;

VarDefList
    : VarDef
    | VarDefList COMMA VarDef // Represents { ',' VarDef }
    ;

VarDef
    : IDENT ConstArraySpecOpt                  // Represents Ident [ '[' ConstExp ']' ]
    | IDENT ConstArraySpecOpt ASSIGN InitVal // Represents Ident [ '[' ConstExp ']' ] '=' InitVal
    ;

InitVal
    : Exp
    | LBRACE InitValListOpt RBRACE
    ;

InitValListOpt
    : InitValList
    | /* empty */       // Represents optional [ InitVal { ',' InitVal } ]
    ;

InitValList
    : InitVal
    | InitValList COMMA InitVal // Represents { ',' InitVal }
    ;

FuncDef
    : FuncType IDENT LPARENT FuncFParamsOpt RPARENT Block { printf("<FuncDef>\n"); }
    ;

MainFuncDef
    : INT MAIN LPARENT RPARENT Block { printf("<MainFuncDef>\n"); }
    ;

FuncType
    : VOID
    | INT
    ;

FuncFParamsOpt
    : FuncFParams
    | /* empty */       // Represents optional [FuncFParams]
    ;

FuncFParams
    : FuncFParam
    | FuncFParams COMMA FuncFParam // Represents { ',' FuncFParam }
    ;

FuncFParam
    : BType IDENT // Array parameters disallowed by this rule
    ;

Block
    : LBRACE BlockItemList RBRACE { printf("<Block>\n"); }
    ;

BlockItemList
    : BlockItemList BlockItem
    | /* empty */       // Represents { BlockItem } zero or more times
    ;

BlockItem
    : Decl
    | Stmt
    ;

Stmt
    : LVal ASSIGN Exp SEMICN              { printf("<Stmt>\n"); }
    | ExpOpt SEMICN                       { printf("<Stmt>\n"); } // Handles [Exp] ';'
    | Block                               // Print occurs in Block rule itself, but counts as Stmt
    | IF LPARENT Cond RPARENT Stmt %prec LOWER_THAN_ELSE { printf("<Stmt>\n"); } // Dangling else resolution
    | IF LPARENT Cond RPARENT Stmt ELSE Stmt { printf("<Stmt>\n"); } // Dangling else resolution
    | WHILE LPARENT Cond RPARENT Stmt     { printf("<Stmt>\n"); }
    | BREAK SEMICN                        { printf("<Stmt>\n"); }
    | CONTINUE SEMICN                     { printf("<Stmt>\n"); }
    | RETURN ExpOpt SEMICN                { printf("<Stmt>\n"); } // Handles return [Exp] ';'
    | LVal ASSIGN GETINT LPARENT RPARENT SEMICN { printf("<Stmt>\n"); }
    | PRINTF LPARENT STR_CONST FuncRParamsCommaListOpt RPARENT SEMICN { printf("<Stmt>\n"); } // Handles {',' Exp}
    ;

ExpOpt
    : Exp
    | /* empty */       // Represents optional [Exp]
    ;

FuncRParamsCommaListOpt
     : /* empty */               // Case: printf("string")
     | COMMA FuncRParams       // Case: printf("string", exp1, ...) represents {',' Exp}
     ;

Cond : LOrExp ;

LVal
    : IDENT ArrayExpSpecOpt // Handles Ident ['[' Exp ']']
    ;

ArrayExpSpecOpt
    : LBRACK Exp RBRACK
    | /* empty */       // Represents optional ['[' Exp ']']
    ;

Exp : AddExp ; // AddExp is the entry point for expressions

Number : INT_CONST ;

PrimaryExp
    : LPARENT Exp RPARENT
    | LVal
    | Number
    ;

UnaryExp
    : PrimaryExp
    | IDENT LPARENT FuncRParamsOpt RPARENT // Function call with optional params
    | PLUS UnaryExp %prec UMINUS       // Unary plus
    | MINU UnaryExp %prec UMINUS       // Unary minus
    | NOT UnaryExp                     // Logical NOT, already high precedence via %right NOT
    ;

UnaryOp // This non-terminal seems unused if handled directly in UnaryExp as above.
    // Keeping it commented out unless needed for semantic actions later.
    // : PLUS
    // | MINU
    // | NOT
    ;

FuncRParamsOpt
    : FuncRParams
    | /* empty */       // Represents optional [FuncRParams]
    ;

FuncRParams
    : Exp
    | FuncRParams COMMA Exp // Represents { ',' Exp }
    ;

MulExp
    : UnaryExp
    | MulExp MULT UnaryExp
    | MulExp DIV UnaryExp
    | MulExp MOD UnaryExp
    ;

AddExp
    : MulExp
    | AddExp PLUS MulExp
    | AddExp MINU MulExp
    ;

RelExp
    : AddExp
    : RelExp LSS AddExp
    | RelExp GRE AddExp
    | RelExp LEQ AddExp
    | RelExp GEQ AddExp
    ;

EqExp
    : RelExp
    | EqExp EQL RelExp
    | EqExp NEQ RelExp
    ;

LAndExp
    : EqExp
    | LAndExp AND EqExp
    ;

LOrExp
    : LAndExp
    | LOrExp OR LAndExp
    ;

ConstExp : AddExp ; // Semantic constraint (Ident must be const) not enforced here syntactically

%%

// Error handling function
void yyerror(const char *s) {
    // Add line number context if possible
    fprintf(stderr, "Syntax error at line %d near '%s': %s\n", yylineno, yytext, s);
    exit(1); // Exit on first error
}

// If you have a separate main file that calls yyparse(), remove the main function below.
int main() {
    // yydebug = 1; // Uncomment for YACC debug traces
    if (yyparse() == 0) {
        // Optional: print success message if needed, but not required by spec
    } else {
        // Error message already printed by yyerror
        return 1; // Indicate failure
    }
    return 0; // Indicate success
}
