#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
int precedence(char c) {
        if (c == '+' || c == '-') {
                return 1;
        }
        if (c == '*' || c == '/') {
                return 2;
        }
        return 0;
}
void infixToPostfix(char *infix, char *postfix) {
        int j = 0;
        for (int i = 0; i < strlen(infix); i++) {
                char current = infix[i];
                if (isalnum(current)) {
                        postfix[j++] = current;
                }
                else if (current == '(') {
                        stack[++top] = current;
                }
                else if (current == ')') {
                        while (top != -1 && stack[top] != '(') {
                                postfix[j++] = stack[top--];
                        }
                top--;
                }
                else if (current == '+' || current == '-' || current == '*' || current == '/') {
                        while (top != -1 && precedence(stack[top]) >= precedence(current)) {
                                postfix[j++] = stack[top--];
                        }
                        stack[++top] = current;
                }
        }
        while (top != -1) {
                postfix[j++] = stack[top--];
        }
        postfix[j] = '\0';
}
int main() {
        char infix[MAX], postfix[MAX];
        printf("Enter infix expression: ");
        scanf("%s",&infix);
        infixToPostfix(infix, postfix);
        printf("Postfix expression: %s\n", postfix);
        return 0;
}
