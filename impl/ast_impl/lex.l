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

"const"             { printf("CONSTTK const\n"); return CONST; }
"int"               { printf("INTTK int\n"); return INT; }
"return"            { printf("RETURNTK return\n"); return RETURN; }
"printf"            { printf("PRINTFTK printf\n"); return PRINTF; }
"getint"            { printf("GETINTTK getint\n"); return GETINT; }
"main"              { printf("MAINTK main\n"); return MAIN; }
"break"             { printf("BREAKTK break\n"); return BREAK; }
"continue"          { printf("CONTINUETK continue\n"); return CONTINUE; }
"if"                { printf("IFTK if\n"); return IF; }
"else"              { printf("ELSETK else\n"); return ELSE; }
"while"             { printf("WHILETK while\n"); return WHILE; }
"void"              { printf("VOIDTK void\n"); return VOID; }

"="                 { printf("ASSIGN =\n"); return ASSIGN; }
"{"                 { printf("LBRACE {\n"); return LBRACE; }
"}"                 { printf("RBRACE }\n"); return RBRACE; }
"("                 { printf("LPARENT (\n"); return LPARENT; }
")"                 { printf("RPARENT )\n"); return RPARENT; }
";"                 { printf("SEMICN ;\n"); return SEMICN; }
","                 { printf("COMMA ,\n"); return COMMA; }
"["                 { printf("LBRACK [\n"); return LBRACK; }
"]"                 { printf("RBRACK ]\n"); return RBRACK; }

"!"                 { printf("NOT !\n"); return NOT; }
"&&"                { printf("AND &&\n"); return AND; }
"||"                { printf("OR ||\n"); return OR; }
"+"                 { printf("PLUS +\n"); return PLUS; }
"-"                 { printf("MINU -\n"); return MINU; }
"*"                 { printf("MULT *\n"); return MULT; }
"/"                 { printf("DIV /\n"); return DIV; }
"%"                 { printf("MOD %%\n"); return MOD; }
"<"                 { printf("LSS <\n"); return LSS; }
"<="                { printf("LEQ <=\n"); return LEQ; }
">"                 { printf("GRE >\n"); return GRE; }
">="                { printf("GEQ >=\n"); return GEQ; }
"=="                { printf("EQL ==\n"); return EQL; }
"!="                { printf("NEQ !=\n"); return NEQ; }

{INTCON}            { printf("INTCON %s\n", yytext); yylval.int_val = strtol(yytext, nullptr, 0); return INT_CONST; }
{IDENFR}            { printf("IDENFR %s\n", yytext); yylval.str_val = my_strdup(yytext); return IDENT; }
{STRCON}            { printf("STRCON %s\n", yytext); yylval.str_val = my_strdup(yytext); return STR_CONST; }
{COMMENT}           {;}

[ \t\r\n]+          ;   // 忽略空白符
.                   { printf("TOKEN: UNKNOWN (%s)\n", yytext); return yytext[0];}


%%