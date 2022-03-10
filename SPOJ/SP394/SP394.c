#include <stdio.h>
#include <string.h>
#define N 5005
char s[N];
long long f[N];
int main() {
  f[0] = f[1] = 1, f[2] = 0;
  while (gets(s + 1) && s[1] != '0') {
    int n = strlen(s + 1);
    for (int i = 2; i <= n; i++) {
      f[i] = (s[i] != '0') ? f[i - 1] : 0;
      int num = (s[i - 1] ^ 48) * 10 + (s[i] ^ 48);
      if (num > 9 && num <= 26) f[i] += f[i - 2];
    }
    printf("%lld\n", f[n]);
  }
}