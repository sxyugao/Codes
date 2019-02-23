#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
#define N 100005
bool lim, f[N][2];
char opt[5];
int main() {
  freopen("testdata.in", "r", stdin);
  int n = read(), m = read();
  f[0][0] = 0, f[0][1] = 1;
  for (int i = 1; i <= n; i++) {
    scanf("%s", opt);
    int x = read();
    if (*opt == 'A') {
      for (int i = 0; i < 31; i++) {
        f[i][0] = f[i][0] & (bool)(x & (1 << i));
        f[i][1] = f[i][1] & (bool)(x & (1 << i));
      }
    }
    if (*opt == 'O') {
      for (int i = 0; i < 31; i++) {
        f[i][0] = f[i][0] | (bool)(x & (1 << i));
        f[i][1] = f[i][1] | (bool)(x & (1 << i));
      }
    }
    if (*opt == 'X') {
      for (int i = 0; i < 31; i++) {
        f[i][0] = f[i][0] ^ (bool)(x & (1 << i));
        f[i][1] = f[i][1] ^ (bool)(x & (1 << i));
      }
    }
  }
  int ans = 0;
  for (int i = 30; ~i; i--) {
    bool mx = m & (1 << i), x = 0;
    if (f[i][0]) {
      ans += (1 << i);
    } else {
      if (f[i][1] && mx) ans += (1 << i);
      x = 1;
    }
    lim &= x == mx;
  }
  printf("%d", ans);
}