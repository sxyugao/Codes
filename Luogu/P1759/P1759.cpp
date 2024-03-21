#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0;
  char gc;
  while (!isdigit(c)) gc;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x;
}
#undef gc
const int N = 205;
int a[N], b[N], c[N];
int f[N][N];
string g[N][N];
int main() {
  int m = read(), v = read(), n = read();
  for (int i = 1; i <= n; ++i) a[i] = read(), b[i] = read(), c[i] = read();
  for (int i = 1; i <= n; ++i)
    for (int j = m; j >= a[i]; --j)
      for (int k = v; k >= b[i]; --k) {
        if (f[j - a[i]][k - b[i]] + c[i] == f[j][k] &&
            g[j - a[i]][k - b[i]] + char(i) < g[j][k]) {
          g[j][k] = g[j - a[i]][k - b[i]] + char(i);
        }
        if (f[j - a[i]][k - b[i]] + c[i] > f[j][k]) {
          f[j][k] = f[j - a[i]][k - b[i]] + c[i];
          g[j][k] = g[j - a[i]][k - b[i]] + char(i);
        }
      }
  printf("%d\n", f[m][v]);
  for (auto x : g[m][v]) printf("%d ", x);
}
