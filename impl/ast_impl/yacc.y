%{
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <memory>
#include <string>
#include <sstream>
#include "ast.h"

extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

// 语法分析完成后的AST根节点
std::unique_ptr<CompUnitAST> root;

%}

// 支持C++特性
%define parse.error verbose
%locations

// 声明类型
%union {
    BaseAST* ast_val;
    ExpAST* exp_val;
    StmtAST* stmt_val;
    DeclAST* decl_val;
    BlockAST* block_val;
    int int_val;
    char* str_val;
}

// 终结符声明
%token CONST INT RETURN PRINTF GETINT MAIN BREAK CONTINUE IF ELSE WHILE VOID
%token ASSIGN LBRACE RBRACE LPARENT RPARENT SEMICN COMMA LBRACK RBRACK
%token NOT AND OR PLUS MINU MULT DIV MOD LSS LEQ GRE GEQ EQL NEQ

%token <int_val> INT_CONST
%token <str_val> IDENT STR_CONST

// 非终结符类型声明
%type <ast_val> CompUnit FuncDef MainFuncDef
%type <decl_val> Decl ConstDecl VarDecl
%type <exp_val> Exp PrimaryExp UnaryExp MulExp AddExp RelExp EqExp LAndExp LOrExp Cond Number ConstExp LVal
%type <exp_val> FuncRParams
%type <stmt_val> Stmt
%type <block_val> Block BlockItem BlockItems

// 定义运算符优先级
%right ASSIGN
%left OR
%left AND
%left EQL NEQ
%left LSS LEQ GRE GEQ
%left PLUS MINU
%left MULT DIV MOD
%right UNARY

// 定义开始符号
%start CompUnit

%%

// 编译单元
CompUnit
    : Decl {
        auto ast = new CompUnitAST();
        ast->global_decls.emplace_back(std::unique_ptr<DeclAST>(static_cast<DeclAST*>($1)));
        root.reset(ast);
        $$ = ast;
    }
    | CompUnit Decl {
        auto ast = static_cast<CompUnitAST*>($1);
        ast->global_decls.emplace_back(std::unique_ptr<DeclAST>(static_cast<DeclAST*>($2)));
        $$ = ast;
    }
    | FuncDef {
        auto ast = new CompUnitAST();
        ast->func_defs.emplace_back(std::unique_ptr<FuncDefAST>(static_cast<FuncDefAST*>($1)));
        root.reset(ast);
        $$ = ast;
    }
    | CompUnit FuncDef {
        auto ast = static_cast<CompUnitAST*>($1);
        ast->func_defs.emplace_back(std::unique_ptr<FuncDefAST>(static_cast<FuncDefAST*>($2)));
        $$ = ast;
    }
    | MainFuncDef {
        auto ast = new CompUnitAST();
        ast->main_func_def.reset(static_cast<MainFuncDefAST*>($1));
        root.reset(ast);
        $$ = ast;
        printf("<CompUnit>\n");
    }
    | CompUnit MainFuncDef {
        auto ast = static_cast<CompUnitAST*>($1);
        ast->main_func_def.reset(static_cast<MainFuncDefAST*>($2));
        $$ = ast;
        printf("<CompUnit>\n");
    }
    ;

// 声明
Decl
    : ConstDecl {
        $$ = $1;
    }
    | VarDecl {
        $$ = $1;
    }
    ;

// 常量声明
ConstDecl
    : CONST INT IDENT ASSIGN ConstExp SEMICN {
        auto ast = new ConstDeclAST();
        ast->type = "int";
        ast->ident = $3;
        ast->init_val.reset(static_cast<ExpAST*>($5));
        free($3);
        printf("<ConstDecl>\n");
        $$ = ast;
    }
    ;

// 变量声明
VarDecl
    : INT IDENT SEMICN {
        auto ast = new VarDeclAST();
        ast->type = "int";
        ast->ident = $2;
        free($2);
        printf("<VarDecl>\n");
        $$ = ast;
    }
    | INT IDENT ASSIGN Exp SEMICN {
        auto ast = new VarDeclAST();
        ast->type = "int";
        ast->ident = $2;
        ast->init_val.reset(static_cast<ExpAST*>($4));
        free($2);
        printf("<VarDecl>\n");
        $$ = ast;
    }
    ;

// 函数定义
FuncDef
    : INT IDENT LPARENT RPARENT Block {
        auto ast = new FuncDefAST();
        ast->return_type = "int";
        ast->func_name = $2;
        ast->body.reset($5);
        free($2);
        printf("<FuncDef>\n");
        $$ = ast;
    }
    | INT IDENT LPARENT FuncFParams RPARENT Block {
        auto ast = new FuncDefAST();
        ast->return_type = "int";
        ast->func_name = $2;
        // 处理参数...（这里简化处理）
        ast->body.reset($6);
        free($2);
        printf("<FuncDef>\n");
        $$ = ast;
    }
    ;

// 函数形参表 (简化版本)
FuncFParams
    : INT IDENT {
        // 简单存储参数，不返回任何值
    }
    ;

// main函数定义
MainFuncDef
    : INT MAIN LPARENT RPARENT Block {
        auto ast = new MainFuncDefAST();
        ast->body.reset($5);
        printf("<MainFuncDef>\n");
        $$ = ast;
    }
    ;

// 语句块
Block
    : LBRACE BlockItems RBRACE {
        $$ = $2;
        printf("<Block>\n");
    }
    | LBRACE RBRACE {
        auto ast = new BlockAST();
        printf("<Block>\n");
        $$ = ast;
    }
    ;

BlockItems
    : BlockItem {
        $$ = $1;
    }
    | BlockItems BlockItem {
        auto block_items = $1;
        auto block_item = static_cast<BlockAST*>($2);
        
        // 将$2中的items全部移动到$1中
        for (auto& item : block_item->items) {
            block_items->items.emplace_back(std::move(item));
        }
        
        // 释放已经移动内容的block_item
        delete block_item;
        
        $$ = block_items;
    }
    ;

BlockItem
    : Decl {
        auto ast = new BlockAST();
        ast->items.emplace_back(std::unique_ptr<BaseAST>(static_cast<BaseAST*>($1)));
        $$ = ast;
    }
    | Stmt {
        auto ast = new BlockAST();
        ast->items.emplace_back(std::unique_ptr<BaseAST>(static_cast<BaseAST*>($1)));
        $$ = ast;
    }
    ;

// 语句
Stmt
    : LVal ASSIGN Exp SEMICN {
        auto ast = new AssignStmtAST();
        ast->lval.reset(static_cast<LValAST*>($1));
        ast->exp.reset(static_cast<ExpAST*>($3));
        printf("<Stmt>\n");
        $$ = ast;
    }
    | LVal ASSIGN GETINT LPARENT RPARENT SEMICN {
        auto ast = new GetIntStmtAST();
        ast->lval.reset(static_cast<LValAST*>($1));
        printf("<Stmt>\n");
        $$ = ast;
    }
    | Exp SEMICN {
        auto ast = new ExprStmtAST();
        ast->exp.reset(static_cast<ExpAST*>($1));
        printf("<Stmt>\n");
        $$ = ast;
    }
    | SEMICN {
        auto ast = new ExprStmtAST();
        printf("<Stmt>\n");
        $$ = ast;
    }
    | Block {
        auto ast = new ExprStmtAST();
        ast->exp = nullptr; // 使用空语句块
        printf("<Stmt>\n");
        $$ = ast;
    }
    | IF LPARENT Cond RPARENT Stmt {
        auto ast = new IfStmtAST();
        ast->cond.reset(static_cast<ExpAST*>($3));
        ast->then_stmt.reset($5);
        ast->else_stmt = nullptr;
        printf("<Stmt>\n");
        $$ = ast;
    }
    | IF LPARENT Cond RPARENT Stmt ELSE Stmt {
        auto ast = new IfStmtAST();
        ast->cond.reset(static_cast<ExpAST*>($3));
        ast->then_stmt.reset($5);
        ast->else_stmt.reset($7);
        printf("<Stmt>\n");
        $$ = ast;
    }
    | WHILE LPARENT Cond RPARENT Stmt {
        auto ast = new WhileStmtAST();
        ast->cond.reset(static_cast<ExpAST*>($3));
        ast->body.reset($5);
        printf("<Stmt>\n");
        $$ = ast;
    }
    | BREAK SEMICN {
        auto ast = new BreakStmtAST();
        printf("<Stmt>\n");
        $$ = ast;
    }
    | CONTINUE SEMICN {
        auto ast = new ContinueStmtAST();
        printf("<Stmt>\n");
        $$ = ast;
    }
    | RETURN Exp SEMICN {
        auto ast = new ReturnStmtAST();
        ast->exp.reset(static_cast<ExpAST*>($2));
        printf("<Stmt>\n");
        $$ = ast;
    }
    | RETURN SEMICN {
        auto ast = new ReturnStmtAST();
        printf("<Stmt>\n");
        $$ = ast;
    }
    | PRINTF LPARENT STR_CONST RPARENT SEMICN {
        auto ast = new PrintfStmtAST();
        ast->format_string = $3;
        free($3);
        printf("<Stmt>\n");
        $$ = ast;
    }
    | PRINTF LPARENT STR_CONST COMMA Exp RPARENT SEMICN {
        auto ast = new PrintfStmtAST();
        ast->format_string = $3;
        ast->args.emplace_back(std::unique_ptr<ExpAST>(static_cast<ExpAST*>($5)));
        free($3);
        printf("<Stmt>\n");
        $$ = ast;
    }
    ;

// 表达式
Exp
    : AddExp {
        $$ = $1;
    }
    ;

// 条件表达式
Cond
    : LOrExp {
        $$ = $1;
    }
    ;

// 左值表达式
LVal
    : IDENT {
        auto ast = new LValAST();
        ast->ident = $1;
        free($1);
        $$ = ast;
    }
    ;

// 基本表达式
PrimaryExp
    : LPARENT Exp RPARENT {
        $$ = $2;
    }
    | LVal {
        $$ = $1;
    }
    | Number {
        $$ = $1;
    }
    ;

// 数值
Number
    : INT_CONST {
        auto ast = new NumberAST();
        ast->value = $1;
        $$ = ast;
    }
    ;

// 一元表达式
UnaryExp
    : PrimaryExp {
        $$ = $1;
    }
    | IDENT LPARENT RPARENT {
        auto ast = new FuncCallAST();
        ast->func_name = $1;
        free($1);
        $$ = ast;
    }
    | IDENT LPARENT FuncRParams RPARENT {
        auto ast = new FuncCallAST();
        ast->func_name = $1;
        
        // 将FuncRParams的参数提取出来
        auto func_params = dynamic_cast<FuncCallAST*>($3);
        if (func_params) {
            ast->args = std::move(func_params->args);
            delete func_params;
        }
        
        free($1);
        $$ = ast;
    }
    | PLUS UnaryExp %prec UNARY {
        auto ast = new UnaryExpAST();
        ast->op = UnaryExpAST::PLUS;
        ast->exp.reset(static_cast<ExpAST*>($2));
        $$ = ast;
    }
    | MINU UnaryExp %prec UNARY {
        auto ast = new UnaryExpAST();
        ast->op = UnaryExpAST::MINUS;
        ast->exp.reset(static_cast<ExpAST*>($2));
        $$ = ast;
    }
    | NOT UnaryExp %prec UNARY {
        auto ast = new UnaryExpAST();
        ast->op = UnaryExpAST::NOT;
        ast->exp.reset(static_cast<ExpAST*>($2));
        $$ = ast;
    }
    ;

// 函数参数
FuncRParams
    : Exp {
        auto ast = new FuncCallAST();
        ast->args.emplace_back(std::unique_ptr<ExpAST>(static_cast<ExpAST*>($1)));
        $$ = ast;
    }
    | FuncRParams COMMA Exp {
        auto ast = static_cast<FuncCallAST*>($1);
        ast->args.emplace_back(std::unique_ptr<ExpAST>(static_cast<ExpAST*>($3)));
        $$ = ast;
    }
    ;

// 乘除模表达式
MulExp
    : UnaryExp {
        $$ = $1;
    }
    | MulExp MULT UnaryExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::MUL;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | MulExp DIV UnaryExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::DIV;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | MulExp MOD UnaryExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::MOD;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    ;

// 加减表达式
AddExp
    : MulExp {
        $$ = $1;
    }
    | AddExp PLUS MulExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::ADD;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | AddExp MINU MulExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::SUB;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    ;

// 关系表达式
RelExp
    : AddExp {
        $$ = $1;
    }
    | RelExp LSS AddExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::LT;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | RelExp GRE AddExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::GT;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | RelExp LEQ AddExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::LE;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | RelExp GEQ AddExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::GE;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    ;

// 相等性表达式
EqExp
    : RelExp {
        $$ = $1;
    }
    | EqExp EQL RelExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::EQ;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    | EqExp NEQ RelExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::NE;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    ;

// 逻辑与表达式
LAndExp
    : EqExp {
        $$ = $1;
    }
    | LAndExp AND EqExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::AND;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    ;

// 逻辑或表达式
LOrExp
    : LAndExp {
        $$ = $1;
    }
    | LOrExp OR LAndExp {
        auto ast = new BinaryExpAST();
        ast->op = BinaryExpAST::OR;
        ast->lhs.reset(static_cast<ExpAST*>($1));
        ast->rhs.reset(static_cast<ExpAST*>($3));
        $$ = ast;
    }
    ;

// 常量表达式
ConstExp
    : AddExp {
        $$ = $1;
    }
    ;

%%

void yyerror(const char* s) {
    fprintf(stderr, "错误: %s\n", s);
}

int main(int argc, char* argv[]) {
    // 设置输入文件
    if (argc > 1) {
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "无法打开文件 %s\n", argv[1]);
            return 1;
        }
    }

    // 执行解析
    yyparse();

    // 输出AST到DOT文件
    if (root) {
        std::ofstream dot_file("ast.dot");
        dot_file << "digraph AST {\n";
        dot_file << "  node [fontname=\"Arial\"];\n";
        dot_file << root->DumpDOT();
        dot_file << "}\n";
        dot_file.close();
    }

    // 关闭文件
    if (argc > 1) {
        fclose(yyin);
    }

    return 0;
} 