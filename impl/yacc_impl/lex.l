%option noyywrap
%{

#include <stdio.h>
#include <stdlib.h>
#include "yacc.tab.h"

%}

INTCON     [0-9]+
IDENFR     [a-zA-Z_][a-zA-Z0-9_]*
STRCON     \"([^\"\\]|\\.)*\" 
COMMENT    "//"[^\n]*


%%

"const"             { return CONST;}
"int"               { return INT;}
"return"            { return RETURN;}
"printf"            { return PRINTF;}
"getint"            { return GETINT;}
"main"              { return MAIN;}
"break"             { return BREAK;}
"continue"          { return CONTINUE;}
"if"                { return IF;}
"else"              { return ELSE;}
"while"             { return WHILE;}
"void"              { return VOID;}

"="                 { return ASSIGN;}
"{"                 { return LBRACE; }
"}"                 { return RBRACE; }
"("                 { return LPARENT; }
")"                 { return RPARENT; }
";"                 { return SEMICN; }
","                 { return COMMA; }
"["                 { return LBRACK; }
"]"                 { return RBRACK; }

"!"                 { return NOT; }
"&&"                 { return AND; }
"||"                 { return OR; }
"+"                 { return PLUS; }
"-"                 { return MINU; }
"*"                 { return MULT; }
"/"                 { return DIV; }
"%"                 { return MOD; }
"<"                 { return LSS; }
"<="                 { return LEQ; }
">"                 { return GRE; }
">="                 { return GEQ; }
"=="                 { return EQL; }
"!="                 { return NEQ; }

{INTCON}            { return INT_CONST;}
{IDENFR}            { return IDENT;}
{STRCON}            { return STR_CONST;}
{COMMENT}           {;}

[ \t\r\n]+          ;   // 忽略空白符
.                   { printf("TOKEN: UNKNOWN (%s)\n", yytext); return yytext[0];}


%%