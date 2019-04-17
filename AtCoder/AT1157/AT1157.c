#include <stdio.h>
int n;
int top, stk[35];
int main() {
    scanf("%d", &n);
    do {
        stk[++top] = n % 2;
        n /= 2;
    } while (n);
    for (int i = 1; i <= top / 2; i++)
        if (stk[i] != stk[top - i + 1]) return puts("No"), 0;
    puts("Yes");
}