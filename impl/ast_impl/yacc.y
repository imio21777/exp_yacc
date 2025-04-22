%{
#define YYDEBUG 1

#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include "ast.h"

// 声明全局根变量
std::unique_ptr<BaseAST> root;

int yylex();
void yyerror(const char *s);
extern char* yytext;

%}

// 定义语义值的可能类型
%union {
    BaseAST* ast_ptr;  // 用于AST节点指针
    int int_val;       // 用于整数值
    char* str_val;     // 用于字符串和标识符名称
}

%token <str_val> IDENT STR_CONST
%token <int_val> INT_CONST

%token MAIN CONST INT BREAK CONTINUE IF ELSE VOID WHILE GETINT PRINTF RETURN NOT AND OR PLUS MINU MULT DIV MOD LSS LEQ GRE GEQ EQL NEQ ASSIGN SEMICN COMMA LPARENT RPARENT LBRACK RBRACK LBRACE RBRACE

%type <ast_ptr> CompUnit Decl ConstDecl VarDecl
%type <ast_ptr> BType MainFuncDef Block BlockItems BlockItem
%type <ast_ptr> Stmt Assignment Number

%start Program /* Define Program as the start symbol */

/* Non-terminal Types (optional for this stage, defaults to int) */

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

/* Grammar Rules based on provided SysY specification */

Program
    : CompUnit { printf("<CompUnit>\n"); }
    ;

CompUnit /* Optional Declarations/Functions followed by Main Function */
    : OptionalTopLevelItems MainFuncDef
    ;

OptionalTopLevelItems
    : /* epsilon */
    | OptionalTopLevelItems TopLevelItem /* Build list */
    ;

TopLevelItem /* Represents one global declaration or non-main function definition */
    : Decl
    | FuncDef /* FuncDef now handles INT/VOID directly */
    ;

Decl /* ConstDecl | VarDecl */
    : ConstDecl SEMICN { printf("<ConstDecl>\n"); }
    | VarDecl SEMICN   { printf("<VarDecl>\n"); }
    ;

ConstDecl /* 'const' BType ConstDef { ',' ConstDef } ';' */
    : CONST INT ConstDefList
    ;

ConstDefList /* ConstDef { ',' ConstDef } */
    : ConstDef
    | ConstDefList COMMA ConstDef /* Left recursion for list */
    ;

ConstDef /* Ident [ '[' ConstExp ']' ] '=' ConstInitVal */
    : IDENT ArraySpecifierOpt ASSIGN ConstInitVal
    ;

ArraySpecifierOpt /* [ '[' ConstExp ']' ] -- Optional array specifier */
    : /* epsilon */
    | LBRACK ConstExp RBRACK
    ;

ConstInitVal /* ConstExp | '{' [ ConstInitVal { ',' ConstInitVal } ] '}' */
    : ConstExp
    | LBRACE RBRACE /* Empty list: {} */
    | LBRACE ConstInitValList RBRACE /* Non-empty list */
    ;

ConstInitValList /* ConstInitVal { ',' ConstInitVal } */
    : ConstInitVal
    | ConstInitValList COMMA ConstInitVal /* Left recursion */
    ;

VarDecl /* BType VarDef { ',' VarDef } ';' */
    : INT VarDefList /* Use INT directly for BType */
    ;

VarDefList /* VarDef { ',' VarDef } */
    : VarDef
    | VarDefList COMMA VarDef /* Left recursion */
    ;

VarDef /* Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal */
    : IDENT ArraySpecifierOpt /* Without initializer */
    | IDENT ArraySpecifierOpt ASSIGN InitVal /* With initializer */
    ;

InitVal /* Exp | '{' [ InitVal { ',' InitVal } ] '}' */
    : Exp
    | LBRACE RBRACE /* Empty list: {} */
    | LBRACE InitValList RBRACE /* Non-empty list */
    ;

InitValList /* InitVal { ',' InitVal } */
    : InitVal
    | InitValList COMMA InitVal /* Left recursion */
    ;

FuncDef /* Handles INT/VOID directly, EXCLUDES main */
    : VOID IDENT LPARENT OptionalFuncFParams RPARENT Block { printf("<FuncDef>\n"); } /* void func */
    | INT  IDENT LPARENT OptionalFuncFParams RPARENT Block { printf("<FuncDef>\n"); } /* int func */
    ;

OptionalFuncFParams /* [FuncFParams] */
    : /* epsilon */
    | FuncFParams
    ;

FuncFParams /* FuncFParam { ',' FuncFParam } */
    : FuncFParam
    | FuncFParams COMMA FuncFParam
    ;

FuncFParam /* BType Ident */
    : INT IDENT
    ;

MainFuncDef /* 'int' 'main' '(' ')' Block */
    : INT MAIN LPARENT RPARENT Block { printf("<MainFuncDef>\n"); }
    ;

Block /* '{' { BlockItem } '}' */
    : LBRACE BlockItemList RBRACE { printf("<Block>\n"); }
    ;

BlockItemList /* { BlockItem } */
    : /* epsilon */
    | BlockItemList BlockItem /* Left recursion */
    ;

BlockItem /* Decl | Stmt */
    : Decl 
    | Stmt
    ;

Stmt
    : LVal ASSIGN Exp SEMICN { printf("<Stmt>\n"); }
    | OptionalExp SEMICN { printf("<Stmt>\n"); } /* Handles [Exp] ';' */
    | Block                { printf("<Stmt>\n"); } /* Added printf for Block as Stmt */
    | IF LPARENT Cond RPARENT Stmt %prec LOWER_THAN_ELSE { printf("<Stmt>\n"); } /* Dangling else handling */
    | IF LPARENT Cond RPARENT Stmt ELSE Stmt { printf("<Stmt>\n"); } /* Dangling else handling */
    | WHILE LPARENT Cond RPARENT Stmt { printf("<Stmt>\n"); }
    | BREAK SEMICN         { printf("<Stmt>\n"); }
    | CONTINUE SEMICN      { printf("<Stmt>\n"); }
    | RETURN OptionalExp SEMICN { printf("<Stmt>\n"); } /* Handles return [Exp] ';' */
    | LVal ASSIGN GETINT LPARENT RPARENT SEMICN { printf("<Stmt>\n"); }
    | PRINTF LPARENT STR_CONST OptionalPrintfArgs RPARENT SEMICN { printf("<Stmt>\n"); }
    ;

OptionalExp /* [Exp] */
    : /* epsilon */
    | Exp
    ;

OptionalPrintfArgs /* { ',' Exp } */
    : /* epsilon */
    | PrintfArgsList
    ;

PrintfArgsList /* ',' Exp { ',' Exp } */
    : COMMA Exp 
    | PrintfArgsList COMMA Exp /* Left recursion */
    ;

Exp     : AddExp    ;
Cond    : LOrExp    ;

LVal    /* Ident ['[' Exp ']'] */
    : IDENT LValArrayOpt
    ;
LValArrayOpt /* ['[' Exp ']'] */
    : /* epsilon */
    | LBRACK Exp RBRACK
    ;

PrimaryExp  : LPARENT Exp RPARENT | LVal | Number ;
Number  : INT_CONST     ;

UnaryExp
    : PrimaryExp
    | IDENT LPARENT OptionalFuncRParams RPARENT /* Function Call */
    | UnaryOp UnaryExp
    ;

OptionalFuncRParams /* [FuncRParams] */
    : /* epsilon */
    | FuncRParams
    ;

FuncRParams /* Exp { ',' Exp } */
    : Exp
    | FuncRParams COMMA Exp /* Left recursion */
    ;

UnaryOp : PLUS | MINU | NOT    ;

/* Standard Expression Hierarchy Rules (remain the same conceptually) */
MulExp  : UnaryExp | MulExp MULT UnaryExp | MulExp DIV UnaryExp | MulExp MOD UnaryExp    ;
AddExp  : MulExp | AddExp PLUS MulExp | AddExp MINU MulExp  ;
RelExp  : AddExp | RelExp LSS AddExp | RelExp GRE AddExp | RelExp LEQ AddExp | RelExp GEQ AddExp ;
EqExp   : RelExp | EqExp EQL RelExp | EqExp NEQ RelExp  ;
LAndExp : EqExp | LAndExp AND EqExp ;
LOrExp  : LAndExp | LOrExp OR LAndExp ;

ConstExp : AddExp ; /* Matches grammar */


%% 

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s near '%s'\n", s, yytext ? yytext : "<unknown>");
    exit(1);
}