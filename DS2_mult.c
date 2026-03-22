//Evaluation of postfix expression (multiple digit numbers )

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX 100

int stack[MAX];
int top = -1;

void push(int val) {
    stack[++top] = val;
}

int pop() {
    return stack[top--];
}

int evaluatePostfix(char* exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        
        if (exp[i] == ' ') continue;

        
        if (isdigit(exp[i])) {
            int num = 0;
            while (isdigit(exp[i])) {
                num = num * 10 + (exp[i] - '0');
                i++;
            }
            push(num);
            i--; 
        } 
        else {
            
            int val1 = pop();
            int val2 = pop();
            
            switch (exp[i]) {
                case '+': push(val2 + val1); break;
                case '-': push(val2 - val1); break;
                case '*': push(val2 * val1); break;
                case '/': push(val2 / val1); break;
            }
        }
    }
    return pop();
}

int main() {
    char postfix[] = "10 20 5 - *"; 
    printf("Postfix Expression: %s\n", postfix);
    printf("Evaluation Result: %d\n", evaluatePostfix(postfix));
    return 0;
}