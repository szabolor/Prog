#include <stdio.h>
#include <string.h>

/*  
odd length      even length
998-7-965       9987-7965
 A  B  C          A    C

I. case: 
    if C < reverse(A):
        A + B + reverse(A)

II. case: 
    if odd length and B < 9:
        A + (B+1) + reverse(A)

III. case:
    if not every element in A is 9:
        if odd length:
            B = 0:
        (A+1) [+ B] + reverse(A+1)

IV. case
    1000...0001 with length of (length+1)
*/ 

#define MAX_L (1000001)
char num[MAX_L] = {0};

int main() {
    int test_cases = 0;
    int i, j, length, middle, carry;
    char smaller, odd = 0;

    scanf("%d\n", &test_cases);
    while (test_cases--) {
        gets(num);
        length = strlen(num);
        odd = length & 1;
        middle = length / 2;

        // I. case:
        i = middle;
        smaller = 0;
        while ((num[i-1] == num[length-i]) && (--i > 0)) {};
        //printf("%d\n", i);
        smaller = (i == 0) ? 0 : (num[i-1] > num[length-i]);
        if (smaller) {
            for (i=0; i<middle; ++i)
                putchar(num[i]);
            for (i=middle-1+odd; i>=0; --i)
                putchar(num[i]);
            putchar('\n');
            continue;
        }

        // II. case
        if (odd && (num[middle] < '9')) {
            for (i=0; i<middle; ++i)
                putchar(num[i]);
            putchar(num[middle]+1);
            for (i=middle-1; i>=0; --i)
                putchar(num[i]);
            putchar('\n');
            continue;
        }

        // III. case
        i = middle;
        while ((num[i-1] == '9') && (--i > 0)) {};
        if (i > 0) {
            carry = 1;
            for (j=middle; j > i; --j)
                num[length-j] = '0';
            //printf(">> %s\n", num);
            for (; i>=0; --i)
                if (num[i-1] + carry > '9') {
                    num[length-i] = '0';
                    //printf("> %c -> %c c:%d\n", num[i-1], num[length-i], carry);
                    carry = 1;
                } else {
                    num[length-i] = num[i-1] + carry;
                    carry = 0;
                    //printf("> %c -> %c c:%d\n", num[i-1], num[length-i], carry);
                }
            //printf("> %s\n", num);
            if (odd) {
                num[middle] = '0';
            }
            for (i=length-1; i>=middle; --i)
                putchar(num[i]);
            for (i=middle+odd; i<length; ++i)
                putchar(num[i]);
            putchar('\n');
            continue;
        }

        // IV. case
        putchar('1');
        for (i=0; i<length-1; ++i)
            putchar('0');
        putchar('1');
        putchar('\n');
    }

    return 0;
}