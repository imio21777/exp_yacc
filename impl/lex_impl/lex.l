%option noyywrap
%{

#include <stdio.h>
#include <stdlib.h>

%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\" 
COMMENT    "//"[^\n]*


%%

"const"             { printf("CONSTTK const\n"); }
"int"               { printf("INTTK int\n"); }
"return"            { printf("RETURNTK return\n"); }
"printf"            { printf("PRINTFTK printf\n"); }
"getint"            { printf("GETINTTK getint\n"); }
"main"              { printf("MAINTK main\n"); }
"break"             { printf("BREAKTK break\n"); }
"continue"          { printf("CONTINUETK continue\n"); }
"if"                { printf("IFTK if\n"); }
"else"              { printf("ELSETK else\n"); }
"while"              { printf("WHILETK while\n"); }
"void"              { printf("VOIDTK void\n"); }

"="                 { printf("ASSIGN =\n"); }
"{"                 { printf("LBRACE %s\n", yytext); }
"}"                 { printf("RBRACE %s\n", yytext); }
"("                 { printf("LPARENT %s\n", yytext); }
")"                 { printf("RPARENT %s\n", yytext); }
";"                 { printf("SEMICN ;\n"); }
","                 { printf("COMMA ,\n"); }
"["                 { printf("LBRACK %s\n", yytext); }
"]"                 { printf("RBRACK %s\n", yytext); }

"!"                 { printf("NOT %s\n", yytext); }
"&&"                 { printf("AND %s\n", yytext); }
"||"                 { printf("OR %s\n", yytext); }
"+"                 { printf("PLUS %s\n", yytext); }
"-"                 { printf("MINU %s\n", yytext); }
"*"                 { printf("MULT %s\n", yytext); }
"/"                 { printf("DIV %s\n", yytext); }
"%"                 { printf("MOD %s\n", yytext); }
"<"                 { printf("LSS %s\n", yytext); }
"<="                 { printf("LEQ %s\n", yytext); }
">"                 { printf("GRE %s\n", yytext); }
">="                 { printf("GEQ %s\n", yytext); }
"=="                 { printf("EQL %s\n", yytext); }
"!="                 { printf("NEQ %s\n", yytext); }

{INTCON}            { printf("INTCON %s\n", yytext); }
{IDENFR}            { printf("IDENFR %s\n", yytext); }
{STRCON}            { printf("STRCON %s\n", yytext); }
{COMMENT}           {}

[ \t\r\n]+          ;   // 忽略空白符
.                   { printf("TOKEN: UNKNOWN (%s)\n", yytext); }


%%

int main(int argc, char *argv[]) {
    yyin = stdin;
    yylex();
    return 0;
}