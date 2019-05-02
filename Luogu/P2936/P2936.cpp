#include <bits/stdc++.h>
using namespace std;
const int N = 205;
const int S = 'A', T = 'Z';
int nedge = 1, head[N], cur[N];
struct Edge {
  int to, nxt, w;
} edge[N * N];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, w;
char x, y;
int d[N];
bool bfs(int S) {
  memset(d, 0, sizeof(d));
  queue<int> q;
  d[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      if (!edge[i].w) continue;
      int y = edge[i].to;
      if (d[y]) continue;
      d[y] = d[x] + 1;
      q.push(y);
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
    if (!edge[i].w || d[x] + 1 != d[y]) continue;
    int f = dfs(y, min(flow - ret, edge[i].w));
    if (f) {
      ret += f;
      edge[i].w -= f;
      edge[i ^ 1].w += f;
    } else {
      d[y] = -1;
    }
  }
  return ret;
}
int dinic() {
  int ans = 0;
  while (bfs(S)) {
    memcpy(cur, head, sizeof(head));
    ans += dfs(S, 1e9);
  }
  return ans;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while (n--) {
    cin >> x >> y >> w;
    add(x, y, w);
    add(y, x, 0);
  }
  cout << dinic() << endl;
}