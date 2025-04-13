#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *productions[] = {
    "E->TE'", "E'->+TE'", "E'->&",
    "T->FT'", "T'->*FT'", "T'->&",
    "F->(E)", "F->i"
};

char *first[] = {
    "(", "+", "&", "(", "*", "&", "(", "i"
};

char *follow[] = {
    "$)", "$)", "$)", "+$)", "+$)", "+$)", "*+$)", "*+$)"
};

char table[6][6][10]; // For 6 non-terminals and 6 terminals
char input[100];
char stack[100];
int top = -1;

char nonTerminals[] = {'E', 'E', 'T', 'T', 'F', 'F'};
char terminals[] = {'i', '+', '*', '(', ')', '$'};

int getRow(char c) {
    switch (c) {
        case 'E': return 0;
        case 'e': return 1;
        case 'T': return 2;
        case 't': return 3;
        case 'F': return 4;
        default: return -1;
    }
}

int getCol(char c) {
    switch (c) {
        case 'i': return 0;
        case '+': return 1;
        case '*': return 2;
        case '(': return 3;
        case ')': return 4;
        case '$': return 5;
        default: return -1;
    }
}

void push(char c) {
    stack[++top] = c;
}

void pop() {
    top--;
}

void displayStack() {
    for (int i = 0; i <= top; i++) {
        printf("%c", stack[i]);
    }
    printf("\t\t");
}

void initializeTable() {
    // Initialize table with "EMPTY"
    for (int i = 0; i < 6; i++)
        for (int j = 0; j < 6; j++)
            strcpy(table[i][j], "EMPTY");

    // Fill parsing table
    strcpy(table[0][0], "E->TE'");    // E on i
    strcpy(table[0][3], "E->TE'");    // E on (

    strcpy(table[1][1], "E'->+TE'");  // E' on +
    strcpy(table[1][4], "E'->&");     // E' on )
    strcpy(table[1][5], "E'->&");     // E' on $

    strcpy(table[2][0], "T->FT'");    // T on i
    strcpy(table[2][3], "T->FT'");    // T on (

    strcpy(table[3][1], "T'->&");     // T' on +
    strcpy(table[3][2], "T'->*FT'");  // T' on *
    strcpy(table[3][4], "T'->&");     // T' on )
    strcpy(table[3][5], "T'->&");     // T' on $

    strcpy(table[4][0], "F->i");      // F on i
    strcpy(table[4][3], "F->(E)");    // F on (
}

int main() {
    int i = 0, j;
    char symbol, x[10];

    initializeTable();

    printf("Enter input string (use 'i' for id) ending with $: ");
    scanf("%s", input);

    top = -1;
    push('$');
    push('E');

    printf("\nStack\t\tInput\t\tAction\n");
    printf("----------------------------------------\n");

    i = 0;
    while (stack[top] != '$') {
        displayStack();
        printf("%s\t\t", &input[i]);

        if (stack[top] == input[i]) {
            printf("Match %c\n", input[i]);
            pop();
            i++;
        } else if (stack[top] >= 'A' && stack[top] <= 'Z') {
            int row = getRow(stack[top]);
            int col = getCol(input[i]);

            if (strcmp(table[row][col], "EMPTY") == 0) {
                printf("Error: No rule for [%c, %c]\n", stack[top], input[i]);
                exit(1);
            } else {
                printf("Apply %s\n", table[row][col]);
                strcpy(x, table[row][col]);
                pop();

                for (j = strlen(x) - 1; x[j] != '>'; j--) {
                    if (x[j] != '&') {
                        push(x[j]);
                    }
                }
            }
        } else {
            printf("Error: Unexpected symbol %c\n", stack[top]);
            exit(1);
        }
    }

    if (input[i] == '$') {
        printf("String Accepted\n");
    } else {
        printf("String Rejected\n");
    }

    return 0;
}
