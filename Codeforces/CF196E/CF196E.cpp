#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 1e5 + 5;
struct Data {
  int x, y;
  long long w;
  bool operator>(const Data &b) const { return w > b.w; }
  bool operator<(const Data &b) const { return w < b.w; }
};
vector<Data> edge;
vector<Data> g[N];
int n, m, from[N];
bool vis[N];
long long d[N];
void dijkstra(const vector<int> &s) {
  memset(d, 0x7f, sizeof(long long) * (n + 5));
  memset(vis, 0, sizeof(bool) * (n + 5));
  priority_queue<Data, vector<Data>, greater<Data>> q;
  for (auto &x : s) {
    d[x] = 0;
    q.push({x, 0, 0});
    from[x] = x;
  }
  while (!q.empty()) {
    int x = q.top().x;
    q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    for (auto &e : g[x]) {
      int y = e.y;
      if (d[x] + e.w < d[y]) {
        d[y] = d[x] + e.w;
        q.push(Data{y, 0, d[y]});
        from[y] = from[x];
      }
    }
  }
}
int f[N];
int find(int x) {
  if (f[x] == x) return x;
  return f[x] = find(f[x]);
}
int main() {
  n = read(), m = read();
  for (int i = 0; i < m; ++i) {
    int x = read(), y = read(), z = read();
    g[x].push_back({0, y, z});
    g[y].push_back({0, x, z});
    edge.push_back({x, y, z});
  }
  vector<int> s;
  s.push_back(1);
  dijkstra(s);
  s.clear();
  int k = read();
  for (int i = 0; i < k; ++i) s.push_back(read());
  long long ans = 1e16;
  for (auto &x : s) ans = min(ans, d[x]);
  dijkstra(s);
  for (int i = 1; i <= n; ++i) f[i] = i;
  for (auto &e : edge) {
    e.w += d[e.x] + d[e.y];
    e.x = from[e.x], e.y = from[e.y];
  }
  sort(edge.begin(), edge.end());
  for (auto &e : edge) {
    int fx = find(e.x), fy = find(e.y);
    if (fx == fy) continue;
    ans += e.w;
    f[fx] = fy;
  }
  cout << ans << endl;
}