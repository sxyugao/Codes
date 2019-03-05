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
const int N = 1e6 + 5;
int cnt[N], f[N][3][3];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) cnt[read()]++;
  for (int i = 1; i <= m; i++)
    for (int j = 0; j < 3; j++)
      for (int k = 0; k < 3; k++)
        for (int l = 0; l < 3; l++) {
          if (j + k + l > cnt[i]) continue;
          f[i][k][l] =
              max(f[i][k][l], f[i - 1][j][k] + (cnt[i] - j - k - l) / 3 + l);
        }
  printf("%d", f[m][0][0]);
}