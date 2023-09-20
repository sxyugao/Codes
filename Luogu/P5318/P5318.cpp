#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using std::memset;
using std::queue;
using std::sort;
using std::vector;
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
const int N = 1e5 + 5;
int n, m, x, y;
bool vis[N];
vector<int> v[N];
void dfs(int x) {
  if (vis[x]) return;
  vis[x] = 1;
  printf("%d ", x);
  if (v[x].empty()) return;
  for (auto y : v[x]) dfs(y);
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; ++i) {
    x = read(), y = read();
    v[x].emplace_back(y);
  }
  for (int i = 1; i <= n; ++i) sort(v[i].begin(), v[i].end());
  dfs(1), puts("");
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.emplace(1);
  vis[1] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    printf("%d ", x);
    for (auto y : v[x])
      if (!vis[y]) {
        q.emplace(y);
        vis[y] = 1;
      }
  }
}