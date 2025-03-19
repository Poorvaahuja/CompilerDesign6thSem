#include <stdio.h>
#include <string.h>

// Function to identify the operator and display in words
void checkOperator(char *input) {
    if (strcmp(input, "+") == 0)
        printf("Addition Operator\n");
    else if (strcmp(input, "-") == 0)
        printf("Subtraction Operator\n");
    else if (strcmp(input, "*") == 0)
        printf("Multiplication Operator\n");
    else if (strcmp(input, "/") == 0)
        printf("Division Operator\n");
    else if (strcmp(input, "%") == 0)
        printf("Modulo Operator\n");
    else if (strcmp(input, "++") == 0)
        printf("Increment Operator\n");
    else if (strcmp(input, "--") == 0)
        printf("Decrement Operator\n");
    else if (strcmp(input, "==") == 0)
        printf("Equal to Operator\n");
    else if (strcmp(input, "!=") == 0)
        printf("Not Equal to Operator\n");
    else if (strcmp(input, ">") == 0)
        printf("Greater than Operator\n");
    else if (strcmp(input, "<") == 0)
        printf("Less than Operator\n");
    else if (strcmp(input, ">=") == 0)
        printf("Greater than or Equal to Operator\n");
    else if (strcmp(input, "<=") == 0)
        printf("Less than or Equal to Operator\n");
    else if (strcmp(input, "&&") == 0)
        printf("Logical AND Operator\n");
    else if (strcmp(input, "||") == 0)
        printf("Logical OR Operator\n");
    else if (strcmp(input, "!") == 0)
        printf("Logical NOT Operator\n");
    else if (strcmp(input, "&") == 0)
        printf("Bitwise AND Operator\n");
    else if (strcmp(input, "|") == 0)
        printf("Bitwise OR Operator\n");
    else if (strcmp(input, "^") == 0)
        printf("Bitwise XOR Operator\n");
    else if (strcmp(input, "<<") == 0)
        printf("Left Shift Operator\n");
    else if (strcmp(input, ">>") == 0)
        printf("Right Shift Operator\n");
    else if (strcmp(input, "=") == 0)
        printf("Assignment Operator\n");
    else if (strcmp(input, "+=") == 0)
        printf("Addition Assignment Operator\n");
    else if (strcmp(input, "-=") == 0)
        printf("Subtraction Assignment Operator\n");
    else if (strcmp(input, "*=") == 0)
        printf("Multiplication Assignment Operator\n");
    else if (strcmp(input, "/=") == 0)
        printf("Division Assignment Operator\n");
    else if (strcmp(input, "%=") == 0)
        printf("Modulo Assignment Operator\n");
    else
        printf("Not an operator\n");
}

int main() {
    char input[5]; // Buffer to store operator input
    printf("Enter an operator: ");
    scanf("%s", input);

    checkOperator(input);

    return 0;
}
