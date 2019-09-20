#include <cstdio>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
char obuf[1 << 14], *p = obuf;
inline void pc(char c) {
  if (obuf + (1 << 14) == p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    p = obuf;
  }
  *p++ = c;
}
inline void fsh() {
  fwrite(obuf, 1, p - obuf, stdout);
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 75000;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N];
vector<int> v[N], son[N];
int d[N], in[N], f[20][N];
queue<int> q;
int lca(int x, int y) {
  if (d[x] < d[y]) swap(x, y);
  for (int i = 18; ~i; i--)
    if (d[x] - (1 << i) >= d[y]) x = f[i][x];
  if (x == y) return x;
  for (int i = 18; ~i; i--)
    if (f[i][x] ^ f[i][y]) x = f[i][x], y = f[i][y];
  return f[0][x];
}
void build(int x) {
  int fa = son[x][0];
  for (auto i = 1; i < son[x].size(); i++) fa = lca(fa, son[x][i]);
  edge[++nedge].to = x;
  edge[nedge].nxt = head[fa];
  head[fa] = nedge;
  d[x] = d[fa] + 1;
  f[0][x] = fa;
  for (int i = 1; i <= 18; i++) f[i][x] = f[i - 1][f[i - 1][x]];
}
void pre() {
  q.push(0);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int y : v[x]) {
      in[y]--;
      if (!in[y]) q.push(y), build(y);
    }
  }
}
int a[N];
void dfs(int x) {
  a[x] = 1;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    dfs(y), a[x] += a[y];
  }
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int x;
    while (x = read()) {
      v[x].emplace_back(i);
      son[i].emplace_back(x);
      in[i]++;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!in[i]) {
      v[0].emplace_back(i);
      son[i].emplace_back(0);
      in[i]++;
    }
  pre(), dfs(0);
  for (int i = 1; i <= n; i++) write(a[i] - 1), pc('\n');
  fsh();
}
