#include <bits/stdc++.h>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const int N = 2e5 + 5;
int n, m, s, t;
vector<int> g[N * 2];
vector<int> f;
int d[N * 2];
bool vis[N * 2];
void init() {
  n = read(), m = read();
  for (int x : f) g[x].clear();
  f.clear();
  for (int i = 0; i < m; ++i) {
    int x = read(), y = read(), c = read() + N;
    g[x].push_back(c);
    g[c].push_back(x);
    g[y].push_back(c);
    g[c].push_back(y);
    vis[x] = vis[y] = vis[c] = 0;
    f.push_back(x);
    f.push_back(y);
    f.push_back(c);
  }
  s = read(), t = read();
}
void solve() {
  queue<int> q;
  q.push(s);
  d[s] = 0;
  vis[s] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    if (x == t) {
      cout << d[x] / 2 << endl;
      return;
    }
    for (int y : g[x])
      if (!vis[y]) {
        d[y] = d[x] + 1;
        vis[y] = 1;
        q.push(y);
      }
  }
}
int main() {
  int T = read();
  while (T--) {
    init();
    solve();
  }
}
