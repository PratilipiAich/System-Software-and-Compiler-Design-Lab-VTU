%{
    #include<stdio.h>
    int id=0, op=0, paran=0;
%}

%%
[0-9]+ {id++; printf("Identifier is %s\n", yytext);}
[+*] {op++; printf("Operator is %s\n", yytext);}
[(] {paran++;}
[)] {paran--;}
%%

int main() {
    printf("Enter an arithmetic expression:\n");
    yylex();

    if(paran==0 && id == op+1 && op>0) {
        printf("Valid Expression!\n");
        printf("No. of identifiers = %d\n", id);
        printf("No. of operators = %d\n", op);
    } else
        printf("Invalid Expression!!\n");
    return 0;
    // Press Ctrl^C while executing to end lex parsing
}

int yywrap() {
    return 1;
}