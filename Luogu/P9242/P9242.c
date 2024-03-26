#include <stdio.h>
#include <string.h>
int n, f[10];
char s[10];
int max(int a, int b) { return a > b ? a : b; }
int main() {
  scanf("%d", &n);
  for (int _ = 0; _ < n; ++_) {
    scanf("%s", s);
    int now = s[strlen(s) - 1] - '0';
    int lst = s[0] - '0';
    f[now] = max(f[now], f[lst] + 1);
  }
  int ans = 0;
  for (int _ = 0; _ < 9; ++_) ans = max(ans, f[_]);
  printf("%d", n - ans);
}