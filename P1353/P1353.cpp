#include <cstdio>
#include <iostream>
using namespace std;
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
const int N = 10005;
const int M = 505;
int a[N], f[N][M];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) f[i][j] = f[i - 1][j - 1] + a[i];
    f[i][0] = f[i - 1][0];
    for (int j = 1; j <= min(i, m); j++) f[i][0] = max(f[i - j][j], f[i][0]);
  }
  printf("%d", f[n][0]);
}