%option noyywrap
%{

#include <cstdlib>
#include <cstring>
#include <string>
#include "ast.h"
#include "yacc.tab.h"

char* my_strdup(const char* s) {
    char* p = (char*)malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

using std::string;
%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\" 
COMMENT    "//"[^\n]*


%%

"const"             { return CONST; }
"int"               { return INT; }
"return"            { return RETURN; }
"printf"            { return PRINTF; }
"getint"            { return GETINT; }
"main"              { return MAIN; }
"break"             { return BREAK; }
"continue"          { return CONTINUE; }
"if"                { return IF; }
"else"              { return ELSE; }
"while"             { return WHILE; }
"void"              { return VOID; }

"="                 { return ASSIGN; }
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"("                 { return LPARENT; }
")"                 { return RPARENT; }
";"                 { return SEMICN; }
","                 { return COMMA; }
"["                 { return LBRACK; }
"]"                 { return RBRACK; }

"!"                 { return NOT; }
"&&"                { return AND; }
"||"                { return OR; }
"+"                 { return PLUS; }
"-"                 { return MINU; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }
"<"                 { return LSS; }
"<="                { return LEQ; }
">"                 { return GRE; }
">="                { return GEQ; }
"=="                { return EQL; }
"!="                { return NEQ; }

{INTCON}            { printf("INTCON %s\n", yytext); yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{IDENFR}            { printf("IDENFR %s\n", yytext); yylval.str_val = my_strdup(yytext); return IDENT; }
{STRCON}            { printf("STRCON %s\n", yytext); yylval.str_val = my_strdup(yytext); return STR_CONST; }
{COMMENT}           {;}

[ \t\r\n]+          ;   // 忽略空白符
.                   { printf("TOKEN: UNKNOWN (%s)\n", yytext); return yytext[0];}


%%