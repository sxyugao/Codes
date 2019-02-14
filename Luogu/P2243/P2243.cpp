#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int N = 251005;
const int M = 1000005;
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[M];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int T, n, m;
int id(int x, int y) { return (x - 1) * (m + 1) + y; }
void init() {
  memset(head, 0, sizeof(head));
  memset(edge, 0, sizeof(edge));
  nedge = 0;
}
char s[505];
int d[N];
struct Data {
  int x, d;
  bool operator<(const Data &b) const { return d > b.d; }
};
priority_queue<Data> q;
bool vis[N];
int Dijkstra(int S, int T) {
  memset(d, 0x3f, sizeof(d));
  memset(vis, 0, sizeof(vis));
  d[S] = 0;
  q.push(Data{S, 0});
  while (!q.empty()) {
    int x = q.top().x;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (d[x] + edge[i].w < d[y]) {
        d[y] = d[x] + edge[i].w;
        if (!vis[y]) q.push(Data{y, d[y]});
      }
    }
  }
  return d[T];
}
int main() {
  scanf("%d", &T);
  while (T--) {
    init();
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s + 1);
      for (int j = 1; j <= m; j++) {
        add(id(i, j), id(i + 1, j + 1), s[j] == '/');
        add(id(i + 1, j + 1), id(i, j), s[j] == '/');
        add(id(i + 1, j), id(i, j + 1), s[j] != '/');
        add(id(i, j + 1), id(i + 1, j), s[j] != '/');
      }
    }
    int ans = Dijkstra(1, id(n + 1, m + 1));
    if (ans > 1e9)
      puts("NO SOLUTION");
    else
      printf("%d\n", ans);
  }
}