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
%type <ast_ptr> MainFuncDef Block BlockItems BlockItem
%type <ast_ptr> Stmt Number
%type <ast_ptr> Exp PrimaryExp UnaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp Cond
%type <ast_ptr> LVal ConstExp FuncDef OptionalFuncFParams FuncFParams FuncFParam
%type <ast_ptr> OptionalExp OptionalTopLevelItems TopLevelItem
%type <ast_ptr> ConstDefList ConstDef ArraySpecifierOpt ConstInitVal ConstInitValList
%type <ast_ptr> VarDefList VarDef InitVal InitValList UnaryOp
%type <ast_ptr> OptionalPrintfArgs PrintfArgsList
%type <ast_ptr> LValArrayOpt OptionalFuncRParams FuncRParams

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
    : CompUnit { 
        root.reset(static_cast<BaseAST*>($1)); // 设置全局根节点
    }
    ;

CompUnit /* Optional Declarations/Functions followed by Main Function */
    : OptionalTopLevelItems MainFuncDef {
        auto ast = new CompUnitAST();
        
        // 处理全局声明和函数
        auto global_items = static_cast<CompUnitAST*>($1);
        if (global_items) {
            ast->global_items = std::move(global_items->global_items);
        }
        
        // 设置主函数
        ast->main_func_def.reset(static_cast<BaseAST*>($2));
        $$ = ast;
    }
    ;

OptionalTopLevelItems
    : /* epsilon */ {
        auto ast = new CompUnitAST();
        $$ = ast;
    }
    | OptionalTopLevelItems TopLevelItem {
        auto ast = static_cast<CompUnitAST*>($1);
        if ($2) {
            ast->global_items.emplace_back(static_cast<BaseAST*>($2));
        }
        $$ = ast;
    }
    ;

TopLevelItem /* Represents one global declaration or non-main function definition */
    : Decl {
        $$ = $1;
    }
    | FuncDef {
        $$ = $1;
    }
    ;

Decl /* ConstDecl | VarDecl */
    : ConstDecl SEMICN { 
        auto ast = new DeclAST();
        ast->kind = DeclAST::CONST_DECL;
        ast->decl.reset(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    | VarDecl SEMICN {
        auto ast = new DeclAST();
        ast->kind = DeclAST::VAR_DECL;
        ast->decl.reset(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    ;

ConstDecl /* 'const' BType ConstDef { ',' ConstDef } ';' */
    : CONST INT ConstDefList {
        $$ = $3; // 直接传递ConstDefList
    }
    ;

ConstDefList /* ConstDef { ',' ConstDef } */
    : ConstDef {
        $$ = $1;
    }
    | ConstDefList COMMA ConstDef {
        $$ = $1; // 当前我们只处理单个定义，可以扩展为列表
    }
    ;

ConstDef /* Ident [ '[' ConstExp ']' ] '=' ConstInitVal */
    : IDENT ArraySpecifierOpt ASSIGN ConstInitVal {
        auto ast = new ConstDeclAST();
        ast->type = TYPE_INT;
        ast->ident = std::string($1);
        
        // 处理数组声明
        // 这里简化了，实际需要从ArraySpecifierOpt获取数组维度
        
        // 处理初始值
        auto init_val = dynamic_cast<NumberAST*>($4);
        if (init_val) {
            ast->value = init_val->value;
        }
        
        // 释放字符串
        free($1);
        
        $$ = ast;
    }
    ;

ArraySpecifierOpt /* [ '[' ConstExp ']' ] -- Optional array specifier */
    : /* epsilon */ {
        $$ = nullptr;
    }
    | LBRACK ConstExp RBRACK {
        $$ = $2; // 传递数组下标表达式
    }
    ;

ConstInitVal /* ConstExp | '{' [ ConstInitVal { ',' ConstInitVal } ] '}' */
    : ConstExp {
        $$ = $1;
    }
    | LBRACE RBRACE {
        $$ = nullptr; // 空数组初始化
    }
    | LBRACE ConstInitValList RBRACE {
        $$ = $2;
    }
    ;

ConstInitValList /* ConstInitVal { ',' ConstInitVal } */
    : ConstInitVal {
        $$ = $1;
    }
    | ConstInitValList COMMA ConstInitVal {
        $$ = $1; // 目前只处理第一个值
    }
    ;

VarDecl /* BType VarDef { ',' VarDef } ';' */
    : INT VarDefList {
        $$ = $2; // 直接传递VarDefList
    }
    ;

VarDefList /* VarDef { ',' VarDef } */
    : VarDef {
        $$ = $1;
    }
    | VarDefList COMMA VarDef {
        $$ = $1; // 当前我们只处理单个定义
    }
    ;

VarDef /* Ident [ '[' ConstExp ']' ] | Ident [ '[' ConstExp ']' ] '=' InitVal */
    : IDENT ArraySpecifierOpt {
        auto ast = new VarDeclAST();
        ast->type = TYPE_INT;
        ast->ident = std::string($1);
        
        // 释放字符串
        free($1);
        
        $$ = ast;
    }
    | IDENT ArraySpecifierOpt ASSIGN InitVal {
        auto ast = new VarDeclAST();
        ast->type = TYPE_INT;
        ast->ident = std::string($1);
        ast->init_val.reset(static_cast<BaseAST*>($4));
        
        // 释放字符串
        free($1);
        
        $$ = ast;
    }
    ;

InitVal /* Exp | '{' [ InitVal { ',' InitVal } ] '}' */
    : Exp {
        $$ = $1;
    }
    | LBRACE RBRACE {
        $$ = nullptr; // 空数组初始化
    }
    | LBRACE InitValList RBRACE {
        $$ = $2;
    }
    ;

InitValList /* InitVal { ',' InitVal } */
    : InitVal {
        $$ = $1;
    }
    | InitValList COMMA InitVal {
        $$ = $1; // 目前只处理第一个值
    }
    ;

FuncDef /* Handles INT/VOID directly, EXCLUDES main */
    : VOID IDENT LPARENT OptionalFuncFParams RPARENT Block { 
        auto ast = new FuncDefAST();
        ast->return_type = TYPE_VOID;
        ast->ident = std::string($2);
        
        // 处理参数
        // 这里简化了，实际需要从OptionalFuncFParams获取参数列表
        
        // 设置函数体
        ast->block.reset(static_cast<BaseAST*>($6));
        
        // 释放字符串
        free($2);
        
        $$ = ast;
    }
    | INT IDENT LPARENT OptionalFuncFParams RPARENT Block { 
        auto ast = new FuncDefAST();
        ast->return_type = TYPE_INT;
        ast->ident = std::string($2);
        
        // 处理参数
        // 这里简化了，实际需要从OptionalFuncFParams获取参数列表
        
        // 设置函数体
        ast->block.reset(static_cast<BaseAST*>($6));
        
        // 释放字符串
        free($2);
        
        $$ = ast;
    }
    ;

OptionalFuncFParams /* [FuncFParams] */
    : /* epsilon */ {
        $$ = nullptr;
    }
    | FuncFParams {
        $$ = $1;
    }
    ;

FuncFParams /* FuncFParam { ',' FuncFParam } */
    : FuncFParam {
        $$ = $1;
    }
    | FuncFParams COMMA FuncFParam {
        $$ = $1; // 目前只处理第一个参数
    }
    ;

FuncFParam /* BType Ident */
    : INT IDENT {
        auto ast = new VarDeclAST(); // 复用VarDeclAST表示参数
        ast->type = TYPE_INT;
        ast->ident = std::string($2);
        
        // 释放字符串
        free($2);
        
        $$ = ast;
    }
    ;

MainFuncDef /* 'int' 'main' '(' ')' Block */
    : INT MAIN LPARENT RPARENT Block { 
        auto ast = new MainFuncDefAST();
        ast->block.reset(static_cast<BaseAST*>($5));
        $$ = ast;
    }
    ;

Block /* '{' { BlockItem } '}' */
    : LBRACE BlockItems RBRACE { 
        $$ = $2;
    }
    | LBRACE RBRACE {
        auto ast = new BlockAST();
        $$ = ast;
    }
    ;

BlockItems /* { BlockItem } */
    : BlockItem {
        auto ast = new BlockAST();
        if ($1) {
            ast->items.emplace_back(static_cast<BaseAST*>($1));
        }
        $$ = ast;
    }
    | BlockItems BlockItem {
        auto ast = static_cast<BlockAST*>($1);
        if ($2) {
            ast->items.emplace_back(static_cast<BaseAST*>($2));
        }
        $$ = ast;
    }
    ;

BlockItem /* Decl | Stmt */
    : Decl {
        $$ = $1;
    }
    | Stmt {
        $$ = $1;
    }
    ;

Stmt
    : LVal ASSIGN Exp SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::ASSIGNMENT;
        
        auto assign = new AssignmentAST();
        auto lval = static_cast<LValAST*>($1);
        if (lval) {
            assign->ident = lval->ident;
        }
        
        ast->content.reset(assign);
        $$ = ast;
    }
    | OptionalExp SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::EXPR;
        ast->content.reset(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    | Block { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::BLOCK;
        ast->content.reset(static_cast<BaseAST*>($1));
        $$ = ast;
    }
    | IF LPARENT Cond RPARENT Stmt %prec LOWER_THAN_ELSE { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::IF;
        ast->content.reset(static_cast<BaseAST*>($3)); // 条件
        ast->else_stmt.reset(static_cast<BaseAST*>($5)); // if块
        $$ = ast;
    }
    | IF LPARENT Cond RPARENT Stmt ELSE Stmt { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::IF;
        ast->content.reset(static_cast<BaseAST*>($3)); // 条件
        ast->else_stmt.reset(static_cast<BaseAST*>($7)); // else块
        // 这里简化处理，实际应该有一个三元结构的if-then-else
        $$ = ast;
    }
    | WHILE LPARENT Cond RPARENT Stmt { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::WHILE;
        ast->content.reset(static_cast<BaseAST*>($3)); // 循环条件
        ast->else_stmt.reset(static_cast<BaseAST*>($5)); // 循环体
        $$ = ast;
    }
    | BREAK SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::BREAK;
        $$ = ast;
    }
    | CONTINUE SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::CONTINUE;
        $$ = ast;
    }
    | RETURN OptionalExp SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::RETURN;
        ast->content.reset(static_cast<BaseAST*>($2)); // 返回表达式
        $$ = ast;
    }
    | LVal ASSIGN GETINT LPARENT RPARENT SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::ASSIGNMENT;
        
        auto assign = new AssignmentAST();
        auto lval = static_cast<LValAST*>($1);
        if (lval) {
            assign->ident = lval->ident;
        }
        
        ast->content.reset(assign);
        $$ = ast;
    }
    | PRINTF LPARENT STR_CONST OptionalPrintfArgs RPARENT SEMICN { 
        auto ast = new StmtAST();
        ast->kind = StmtAST::PRINTF;
        
        // 这里简化处理printf，实际需要保存格式串和参数列表
        
        // 释放字符串
        free($3);
        
        $$ = ast;
    }
    ;

OptionalExp /* [Exp] */
    : /* epsilon */ {
        $$ = nullptr;
    }
    | Exp {
        $$ = $1;
    }
    ;

OptionalPrintfArgs /* { ',' Exp } */
    : /* epsilon */ {
        $$ = nullptr;
    }
    | PrintfArgsList {
        $$ = $1;
    }
    ;

PrintfArgsList /* ',' Exp { ',' Exp } */
    : COMMA Exp {
        $$ = $2;
    }
    | PrintfArgsList COMMA Exp {
        $$ = $1; // 目前只处理第一个参数
    }
    ;

Exp : AddExp { $$ = $1; } ;
Cond : LOrExp { $$ = $1; } ;

LVal /* Ident ['[' Exp ']'] */
    : IDENT LValArrayOpt {
        auto ast = new LValAST();
        ast->ident = std::string($1);
        
        // 处理数组索引
        // 这里简化处理，实际需要从LValArrayOpt获取索引列表
        
        // 释放字符串
        free($1);
        
        $$ = ast;
    }
    ;

LValArrayOpt /* ['[' Exp ']'] */
    : /* epsilon */ {
        $$ = nullptr;
    }
    | LBRACK Exp RBRACK {
        $$ = $2;
    }
    ;

PrimaryExp
    : LPARENT Exp RPARENT { $$ = $2; }
    | LVal { $$ = $1; }
    | Number { $$ = $1; }
    ;

Number
    : INT_CONST {
        auto ast = new NumberAST();
        ast->value = $1;
        $$ = ast;
    }
    ;

UnaryExp
    : PrimaryExp { $$ = $1; }
    | IDENT LPARENT OptionalFuncRParams RPARENT {
        auto ast = new ExprAST();
        ast->kind = ExprAST::CALL;
        ast->ident = std::string($1);
        
        // 处理函数参数
        // 这里简化处理，实际需要保存参数列表
        
        // 释放字符串
        free($1);
        
        $$ = ast;
    }
    | UnaryOp UnaryExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::UNARY;
        ast->op = static_cast<ExprAST*>($1)->op;
        ast->right.reset(static_cast<BaseAST*>($2));
        $$ = ast;
    }
    ;

OptionalFuncRParams /* [FuncRParams] */
    : /* epsilon */ {
        $$ = nullptr;
    }
    | FuncRParams {
        $$ = $1;
    }
    ;

FuncRParams /* Exp { ',' Exp } */
    : Exp {
        $$ = $1;
    }
    | FuncRParams COMMA Exp {
        $$ = $1; // 目前只处理第一个参数
    }
    ;

UnaryOp
    : PLUS {
        auto ast = new ExprAST();
        ast->op = "+";
        $$ = ast;
    } 
    | MINU {
        auto ast = new ExprAST();
        ast->op = "-";
        $$ = ast;
    } 
    | NOT {
        auto ast = new ExprAST();
        ast->op = "!";
        $$ = ast;
    }
    ;

/* Standard Expression Hierarchy Rules (remain the same conceptually) */
MulExp
    : UnaryExp { $$ = $1; }
    | MulExp MULT UnaryExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "*";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | MulExp DIV UnaryExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "/";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | MulExp MOD UnaryExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "%";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    }
    ;

AddExp
    : MulExp { $$ = $1; }
    | AddExp PLUS MulExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "+";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | AddExp MINU MulExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "-";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    }
    ;

RelExp
    : AddExp { $$ = $1; }
    | RelExp LSS AddExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "<";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | RelExp GRE AddExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = ">";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | RelExp LEQ AddExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "<=";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | RelExp GEQ AddExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = ">=";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    }
    ;

EqExp
    : RelExp { $$ = $1; }
    | EqExp EQL RelExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "==";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    } 
    | EqExp NEQ RelExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "!=";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    }
    ;

LAndExp
    : EqExp { $$ = $1; }
    | LAndExp AND EqExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "&&";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    }
    ;

LOrExp
    : LAndExp { $$ = $1; }
    | LOrExp OR LAndExp {
        auto ast = new ExprAST();
        ast->kind = ExprAST::BINARY;
        ast->op = "||";
        ast->left.reset(static_cast<BaseAST*>($1));
        ast->right.reset(static_cast<BaseAST*>($3));
        $$ = ast;
    }
    ;

ConstExp : AddExp { $$ = $1; }; /* Matches grammar */


%% 

void yyerror(const char *s) {
    fprintf(stderr, "Syntax error: %s near '%s'\n", s, yytext ? yytext : "<unknown>");
    exit(1);
}