#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define N 1000005
int n, f[N][2];
char s[N];
int main() {
    scanf("%d", &n);
    scanf("%s", s + 1);
    for (int i = 1; i <= n; i++) {
        if (s[i] == 'A') {
            f[i][0] = min(f[i - 1][0], f[i - 1][1] + 1);
            f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1] + 1);
        }
        if (s[i] == 'B') {
            f[i][0] = min(f[i - 1][0] + 1, f[i - 1][1] + 1);
            f[i][1] = min(f[i - 1][0] + 1, f[i - 1][1]);
        }
    }
    printf("%d", f[n][0]);
}