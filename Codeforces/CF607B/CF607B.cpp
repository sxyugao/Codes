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
const int N = 505;
int a[N], f[N][N];
int dfs(int l, int r) {
  if (l >= r) return 1;
  if (f[l][r]) return f[l][r];
  int ans = a[l] == a[r] ? dfs(l + 1, r - 1) : 1e9;
  for (int i = l; i < r; i++)
    ans = min(ans, dfs(l, i) + dfs(i + 1, r));
  return f[l][r] = ans;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  printf("%d", dfs(1, n));
}