#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define gc c = getchar()
long long read() {
  long long x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e5 + 5;
long long a[N];
int num[5], f[150][150], v[150][150];
int tot, id[N];
int getId(int x) {
  if (!id[x]) id[x] = ++tot;
  return id[x];
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  memset(v, 0x3f, sizeof(v));
  memset(f, 0x3f, sizeof(f));
  for (int j = 0; j < 64; j++) {
    *num = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] & (1LL << j)) {
        num[++*num] = i;
        if (*num > 2) return puts("3"), 0;
      }
    if (*num < 2) continue;
    int x = getId(num[1]), y = getId(num[2]);
    v[x][y] = v[y][x] = 1;
    f[x][y] = f[y][x] = 1;
  }
  int ans = 1e9;
  for (int k = 1; k <= tot; k++) {
    for (int i = 1; i < k; i++)
      for (int j = i + 1; j < k; j++) {
        long long tmp = 1LL * v[i][k] + 1LL * v[k][j] + 1LL * f[i][j];
        if (tmp < ans) ans = tmp;
      }
    for (int i = 1; i <= tot; i++)
      for (int j = 1; j <= tot; j++)
        f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
  }
  if (ans == 1e9) return puts("-1"), 0;
  printf("%d", ans);
}
