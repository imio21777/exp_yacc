%option noyywrap
%{

#include "yacc.tab.h"

char* my_strdup(const char* s) {
    char* p = (char*)malloc(strlen(s) + 1);
    if (p) strcpy(p, s);
    return p;
}

%}

%%
"main"              { printf("MAINTK main\n"); return MAIN; }
"const"             { printf("CONSTTK const\n"); return CONST; }
"int"               { printf("INTTK int\n"); return INT; } 
"getint"            { printf("GETINTTK getint\n"); return GETINT; }
"printf"            { printf("PRINTFTK printf\n"); return PRINTF; }
"return"            { printf("RETURNTK return\n"); return RETURN; }

{IDENFR}     { yylval.str_val = my_strdup(yytext); return IDENT; }
{INT_CONST}  { yylval.int_val = atoi(yytext); return INT_CONST; }

%%