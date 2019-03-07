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
const int P = 19260817;
const int N = 1005;
int c[N][N], sum[N][N];
int main() {
  c[0][0] = 1;
  for (int i = 1; i < N; i++) {
    c[i][0] = 1;
    for (int j = 1; j <= i; j++) c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % P;
  }
  for (int i = 1; i < N; i++)
    for (int j = 1; j < N; j++) {
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + c[i][j];
      sum[i][j] %= P;
      sum[i][j] = (sum[i][j] + P) % P;
    }
  for (int q = read(); q; q--) {
    int n = read(), m = read();
    printf("%d\n", sum[m][n]);
  }
}