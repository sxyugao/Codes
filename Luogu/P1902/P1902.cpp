#include <cstdio>
#include <cstring>
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
const int INF = 0x7fffffff;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, a[N][N];
bool vis[N][N];
void dfs(int x, int y, int l) {
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (a[x][y] > l) return;
  if (vis[x][y]) return;
  vis[x][y] = 1;
  for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i], l);
}
bool check(int x) {
  memset(vis, 0, sizeof(vis));
  dfs(1, 1, x);
  for (int i = 1; i <= m; i++)
    if (!vis[n][i]) return 0;
  return 1;
}
int main() {
  n = read(), m = read();
  int l = 0, r = 0, ans = INF;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      a[i][j] = read();
      r = max(r, a[i][j]);
    }
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d", ans);
}