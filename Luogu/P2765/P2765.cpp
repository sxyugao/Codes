#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 5005;
const int M = 5000005;
const int S = N << 1, T = N << 1 | 1;
int nedge = 1, head[T + 5], cur[T + 5];
struct Edge {
  int to, nxt, w;
} edge[M];
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
int d[T + 5], nxt[T + 5];
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
        ret += f;
        edge[i].w -= f;
        edge[i ^ 1].w += f;
        nxt[x >> 1] = y >> 1;
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
int n, ball, h[T + 5];
int main() {
  scanf("%d", &n);
  int num = 0;
  while (num <= n) {
    ball++;
    add(S, ball << 1, 1);
    add((ball << 1) | 1, T, 1);
    for (int i = sqrt(ball) + 1; i * i - ball < ball; i++) {
      add((i * i - ball) << 1, ball << 1 | 1, 1);
    }
    int flow = dinic();
    if (!flow) h[++num] = ball;
  }
  printf("%d\n", ball - 1);
  for (int i = 1; i <= n; i++) {
    for (int j = h[i]; j && j != T >> 1; j = nxt[j]) printf("%d ", j);
    puts("");
  }
}