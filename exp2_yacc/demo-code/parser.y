%{
#include <stdio.h>
#include <stdlib.h>

int yylex();
void yyerror(const char *s);
%}

%token DIGIT       // 定义终结符
%left '+' '-'      // 定义结合性和优先级 
%left '*' '/'

%%
R   : E         { $$ = $1; printf("%d\n", $$); }

E   : E '+' T   { $$ = $1 + $3; }
    | E '-' T   { $$ = $1 - $3; }
    | T         { $$ = $1; }
;

T   : T '*' F   { $$ = $1 * $3; }
    | T '/' F   {
                    if ($3 == 0) {
                        yyerror("divide by zero");
                        YYABORT;
                }
                $$ = $1 / $3;
            }
    | F         { $$ = $1; }
;

F   : '(' E ')' { $$ = $2; }
    | DIGIT     { $$ = $1; }
;
%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    return yyparse();
}