#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;

// Push function
void push(char item) {
stack[++top] = item;
}

// Pop function
char pop() {
return stack[top--];
}

// Check precedence
int precedence(char ch) {
if (ch == '^')
return 3;
else if (ch == '*' || ch == '/')
return 2;
else if (ch == '+' || ch == '-')
return 1;
else
return 0;
}

int main() {
char infix[MAX], postfix[MAX];
int i, j = 0;
printf("Enter Infix Expression: ");
scanf("%s", infix);
for (i = 0; infix[i] != '\0'; i++) {

// If operand, add to postfix
if (isalnum(infix[i])) {
postfix[j++] = infix[i];
}

// If '(' push to stack
else if (infix[i] == '(') {
push(infix[i]);
}

// If ')' pop until '('
else if (infix[i] == ')') {
while (stack[top] != '(') {
postfix[j++] = pop();
}
pop(); // Remove '('
}

// Operator
else {
while (top != -1 &&
precedence(stack[top]) >= precedence(infix[i])) {
postfix[j++] = pop();
}
push(infix[i]);
}
}

// Pop remaining operators
while (top != -1) {
postfix[j++] = pop();
}
postfix[j] = '\0';
printf("Postfix Expression: %s\n", postfix);
return 0;
}
