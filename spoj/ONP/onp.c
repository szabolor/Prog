#include <stdio.h>

#define MAX_L (500)
int test_case = 0;
char expr[MAX_L] = {0};

int eval(int start) {
    int i;
    char op = '@';
    for (i = 0; start + i < MAX_L; ++i) {
        if (expr[start+i] == ')') {
            putchar(op);
            return i+1;
        }
        else if (expr[start+i] >= 'a' && expr[start+i] <= 'z')
            putchar(expr[start+i]);
        else if (expr[start+i] == '(')
            i += eval(start+i+1);
        else
            op = expr[start+i];
    } 
}

int main() {
    scanf("%d\n", &test_case);

    while (test_case--) {
        gets(expr);
        eval(1);
        putchar('\n');
    }

    return 0;
}