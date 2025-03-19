#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

char *expr;  // Input expression pointer

// Function prototypes
int E();  // Parses expressions
int T();  // Parses terms
int F();  // Parses factors

// Function to get the next character
char peek() {
    return *expr;
}

// Function to consume the next character
void consume() {
    expr++;
}

// Function to parse an integer number
int number() {
    int value = 0;
    while (isdigit(peek())) {
        value = value * 10 + (peek() - '0');
        consume();
    }
    return value;
}

// Parsing Functions
int E() {
    int result = T();
    while (peek() == '+' || peek() == '-') {
        char op = peek();
        consume();
        int term = T();
        if (op == '+') result += term;
        else result -= term;
    }
    return result;
}

int T() {
    int result = F();
    while (peek() == '*' || peek() == '/') {
        char op = peek();
        consume();
        int factor = F();
        if (op == '*') result *= factor;
        else if (factor != 0) result /= factor;  // Handle division by zero
        else {
            printf("Error: Division by zero!\n");
            exit(1);
        }
    }
    return result;
}

int F() {
    if (peek() == '(') {  // Parenthesized Expression
        consume();  // Consume '('
        int result = E();
        if (peek() == ')') consume();  // Consume ')'
        else {
            printf("Error: Missing closing parenthesis!\n");
            exit(1);
        }
        return result;
    } else if (isdigit(peek())) {  // Number
        return number();
    } else {
        printf("Error: Unexpected character '%c'\n", peek());
        exit(1);
    }
}

int main() {
    char input[100];
    printf("Enter an arithmetic expression: ");
    scanf("%s", input);
    expr = input;

    int result = E();
    if (peek() != '\0') {
        printf("Error: Unexpected characters at end of input!\n");
    } else {
        printf("Result: %d\n", result);
    }
    return 0;
}
