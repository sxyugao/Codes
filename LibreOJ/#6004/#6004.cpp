#include <bits/stdc++.h>
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
const int N = 105;
const int M = 300;
const int S = 406, T = 407;
int nedge = 1, head[T + 5], cur[T + 5];
struct Edge {
  int to, nxt, w;
} edge[N * T * 2];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int d[T + 5];
bool bfs() {
  memset(d, 0, sizeof(d));
  queue<int> q;
  d[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (edge[i].w && !d[y]) {
        d[y] = d[x] + 1;
        q.push(y);
      }
    }
  }
  return d[T];
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int ret = 0;
  for (int i = cur[x]; i; i = edge[i].nxt) {
    cur[x] = i;
    int y = edge[i].to;
    if (edge[i].w && d[x] + 1 == d[y]) {
      int f = dfs(y, min(flow - ret, edge[i].w));
      if (f) {
        edge[i].w -= f;
        edge[i ^ 1].w += f;
        ret += f;
      } else {
        d[y] = -1;
      }
    }
  }
  return ret;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    memcpy(cur, head, sizeof(head));
    ans += dfs(S, 1e9);
  }
  return ans;
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      add(i, j + n, 1);
      add(j + n, i, 0);
    }
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x = read();
    sum += x;
    add(S, i, x);
    add(i, S, 0);
  }
  for (int i = 1; i <= m; i++) {
    add(i + n, T, read());
    add(T, i + n, 0);
  }
  if (dinic() < sum) return puts("0"), 0;
  puts("1");
  for (int i = 1; i <= n; i++) {
    for (int j = head[i]; j; j = edge[j].nxt) {
      if (edge[j].w) continue;
      printf("%d ", edge[j].to - n);
    }
    puts("");
  }
}