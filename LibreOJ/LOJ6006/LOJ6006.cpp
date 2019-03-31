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
const int N = 2005;
const int S = 2005, T = 2006;
int nedge = 1, head[T + 5], cur[T + 5];
struct Edge {
  int to, nxt, w;
} edge[N * (N + 3)];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
  edge[++nedge].to = x;
  edge[nedge].w = 0;
  edge[nedge].nxt = head[y];
  head[y] = nedge;
}
int d[T + 5];
bool bfs() {
  memset(d, 0, sizeof(d));
  d[S] = 1;
  queue<int> q;
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
int nxt[T + 5];
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
        nxt[x] = y;
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
vector<int> v[25];
int sum;
int main() {
  int k = read(), n = read();
  for (int i = 1; i <= k; i++) {
    int x = read();
    add(n + i, T, x);
    sum += x;
  }
  for (int i = 1; i <= n; i++) add(S, i, 1);
  for (int i = 1; i <= n; i++)
    for (int num = read(); num; num--) {
      int id = read();
      add(i, n + id, 1e9);
    }
  if (dinic() < sum) return puts("No Solution!"), 0;
  for (int i = 1; i <= n; i++)
    if (nxt[i]) v[nxt[i] - n].push_back(i);
  for (int i = 1; i <= k; i++) {
    printf("%d:", i);
    for (int x : v[i]) printf(" %d", x);
    puts("");
  }
}