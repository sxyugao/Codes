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
queue<int> q;
int d[1005];
bool vis[1005];
int nedge, head[1005];
struct Edge {
  int to, w, nxt;
} edge[20005];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int main() {
  int n = read(), m = read(), k = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  int l = 0, r = 1e6, ans = -1;
  while (l <= r) {
    int mid = (l + r) >> 1;
    memset(d, 0x7f, sizeof(d));
    memset(vis, 0, sizeof(vis));
    d[1] = 0;
    q.push(1);
    vis[1] = 1;
    while (!q.empty()) {
      int now = q.front();
      q.pop();
      vis[now] = 0;
      for (int i = head[now]; i; i = edge[i].nxt) {
        int u = edge[i].to;
        if (d[now] + (edge[i].w > mid) < d[u]) {
          d[u] = d[now] + (edge[i].w > mid);
          if (!vis[u]) {
            vis[u] = 1;
            q.push(u);
          }
        }
      }
    }
    if (d[n] <= k) {
      ans = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d", ans);
}