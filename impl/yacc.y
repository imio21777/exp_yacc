%{

#include <cstdio>
#include <cstdlib>
#include <string>
#include <memory>
#include "ast.h"

std::unique_ptr<BaseAST> root;
%}

// %token MAIN CONST INT BREAK CONTINUE IF ELSE
// %token WHILE GETINT PRINTF RETURN VOID
// %token IDENT INT_CONST STR_CONST

%union {
    BaseAST* ast_ptr;    // 指向 AST 节点
    int int_val;         // 整数字面量
    char* str_val;       // 标识符和字符串字面量
}

%token <str_val> IDENT STR_CONST
%token <int_val> INT_CONST

%type <ast_ptr> CompUnit Decl ConstDecl VarDecl
%type <ast_ptr> BType MainFuncDef Block BlockItems BlockItem
%type <ast_ptr> Stmt Assignment Number

%%

// CompUnit -> {Decl} {FuncDef} MainFuncDef
CompUnit
    : Decl MainFuncDef {
        printf("<CompUnit>\n");
    }
    ;

Decl : 
    ConstDecl ';' {
        printf("<Decl>\n");
    } | VarDecl ';' {
        printf("<Decl>\n");
    }
    ;

Number :
    INT_CONST {
        auto ast = new NumberAST();
        ast->value = $1;
        $$ = ast;
    }
    ;

// ConstDecl -> 'const' xxx
ConstDecl :
    CONST BType IDENT '=' Number {
        auto ast = new ConstDeclAST();
        ast->type = TYPE_INT;       // 假设默认类型为 int
        ast->ident = $3;            // 标识符名称
        auto number = dynamic_cast<NumberAST*>($5);
        if (number) ast->value = number->value;
        $$ = ast;
    }
    ;

%%

int main() {
    yydebug = 0;  // 1为启用调试，0为不启用调试
    return yyparse();
}