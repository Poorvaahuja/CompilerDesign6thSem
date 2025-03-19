%{
#include <stdio.h>
%}
%%
[a-zA-Z|a-z0-9A-Z]+    printf("Identifier: %s\n", yytext);
[0-9]+       printf("Number: %s\n", yytext);
.            printf("Symbol: %s\n", yytext);
\n           /* Ignore newlines */
<<EOF>>      return 0;  /* Stop processing on EOF */
%%
int main() {
    yylex();
    return 0;
}
int yywrap() {
    return 1;
}
