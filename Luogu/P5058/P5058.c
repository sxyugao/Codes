#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#define N 105
#define min(a, b) ((a) < (b) ? (a) : (b))
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
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N * N * 2];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int tot, dfn[N], low[N];
int S, T, ans;
void dfs(int x, int lst) {
  dfn[x] = low[x] = ++tot;
  int cnt = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (!dfn[y]) {
      dfs(y, x);
      cnt++;
      low[x] = min(low[x], low[y]);
      bool f = (!lst && cnt > 1) || (lst && low[y] >= dfn[x]);
      if (f && dfn[y] <= dfn[T] && (x ^ S) && (x ^ T)) ans = min(ans, x);
    } else if (y != lst) {
      low[x] = min(low[x], dfn[y]);
    }
  }
}
int main() {
  int n = read();
  S = read(), T = read();
  while (S || T) {
    add(S, T), add(T, S);
    S = read(), T = read();
  }
  S = read(), T = read();
  ans = n + 1;
  dfs(S, 0);
  if (ans <= n) return printf("%d", ans), 0;
  puts("No solution");
}