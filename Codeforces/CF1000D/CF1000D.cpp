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
const int N = 1005;
const int P = 998244353;
int c[N][N], a[N], f[N];
void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  c[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    c[i][0] = c[i][i] = 1;
    for (int j = 1; j < i; j++)
      c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % P;
  }
  f[n + 1] = 1;
  for (int i = n; i; i--) {
    if (a[i] <= 0) continue;
    for (int j = i + a[i] + 1; j <= n + 1; j++)
      Add(f[i], 1LL * f[j] * c[j - i - 1][a[i]] % P);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans += f[i];
    if (ans >= P) ans -= P;
  }
  printf("%d", ans);
}
