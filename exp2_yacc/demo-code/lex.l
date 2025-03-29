%option noyywrap
%{
#include "parser.tab.h"
%}

%%
[0-9]+    { yylval = atoi(yytext); return DIGIT; }
[+\-*/()] { return yytext[0]; }
[ \t\n]   ; // 忽略空白字符
.         { return yytext[0]; }
%%