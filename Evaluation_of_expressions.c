#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    double items[MAX_STACK_SIZE];
} Stack;


void push(Stack *s, double value);
double pop(Stack *s);
double evaluateExpression(char *expression);

int main() {
    char expression[100];
    
    printf("Enter the expression: ");
    fgets(expression, sizeof(expression), stdin);
    
    double result = evaluateExpression(expression);
    printf("Result: %.2f\n", result);
    
    return 0;
}


void push(Stack *s, double value) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
}


double pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return s->items[(s->top)--];
}


double evaluateExpression(char *expression) {
    Stack operandStack;
    operandStack.top = -1;

    char *ptr = expression;
    while (*ptr != '\0') {
        if (isdigit(*ptr)) {
            push(&operandStack, atof(ptr));
            while (isdigit(*ptr) || *ptr == '.') 
                ptr++;
        } else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            double operand2 = pop(&operandStack);
            double operand1 = pop(&operandStack);
            double result;
            switch (*ptr) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
            }
            push(&operandStack, result);
            ptr++;
        } else {
            ptr++;
        }
    }

    return pop(&operandStack); 
}

