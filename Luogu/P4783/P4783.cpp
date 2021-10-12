#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - 48;
  return x * f;
}
const int N = 405;
const int P = 1e9 + 7;
int a[N][2 * N];
int pw(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return ans;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    a[i][i + n] = 1;
    for (int j = 1; j <= n; j++) a[i][j] = read();
  }
  for (int i = 1; i <= n; i++) {
    if (!a[i][i]) return puts("No Solution"), 0;
    int inv = pw(a[i][i], P - 2);
    for (int j = 1; j <= n; j++) {
      if (i == j) continue;
      int tmp = 1LL * a[j][i] * inv % P;
      for (int k = i; k <= 2 * n; k++)
        a[j][k] = ((a[j][k] - 1LL * tmp * a[i][k] % P) % P + P) % P;
    }
    for (int j = 1; j <= 2 * n; j++) a[i][j] = 1LL * a[i][j] * inv % P;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = n + 1; j <= 2 * n; j++) printf("%d ", a[i][j]);
    puts("");
  }
}