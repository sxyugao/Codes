#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
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
typedef long long LL;
const int INF = 0x7fffffff;
const int N = 105;
const int M = 5005;
int nedge = 1, head[N], cur[N];
struct Edge {
  int to, nxt, w;
} edge[M << 1];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int d[N];
bool bfs(int s, int t) {
  memset(d, 0, sizeof(d));
  d[s] = 1;
  queue<int> q;
  q.push(s);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (!d[y] && edge[i].w) {
        d[y] = d[x] + 1;
        if (y == t) return 1;
        q.push(y);
      }
    }
  }
  return 0;
}
int dfs(int x, int t, int flow) {
  if (x == t) return flow;
  int ret = 0;
  for (int i = cur[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    cur[x] = i;
    if (edge[i].w && d[y] == d[x] + 1) {
      int f = dfs(y, t, min(flow - ret, edge[i].w));
      if (f) {
        ret += f;
        edge[i].w -= f;
        edge[i ^ 1].w += f;
      } else {
        d[y] = -1;
      }
    }
  }
  return ret;
}
LL dinic(int s, int t) {
  LL ans = 0;
  while (bfs(s, t)) {
    memcpy(cur, head, sizeof(head));
    ans += dfs(s, t, INF);
  }
  return ans;
}
int main() {
  int n = read(), m = read(), s = read(), t = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, 0);
  }
  printf("%lld", dinic(s, t));
}