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
const int N = 1e4 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int ans, f[N], g[N];
void dfs(int x, int fa) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
    int tmp = f[y] + 1;
    if (tmp > f[x]) {
      g[x] = f[x];
      f[x] = tmp;
    } else {
      g[x] = max(g[x], tmp);
    }
  }
  ans = max(ans, f[x] + g[x]);
}
int main() {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  printf("%d", ans);
}