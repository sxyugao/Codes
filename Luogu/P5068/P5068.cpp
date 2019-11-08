#include <bitset>
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
const int N = 1005;
vector<int> g[N];
bitset<N> f[N][N];
queue<int> Q;
int n, m, q, d[N];
inline void bfs(int S) {
  for (int i = 1; i <= n; i++) d[i] = -1;
  Q.push(S);
  d[S] = 0;
  while (!Q.empty()) {
    int x = Q.front();
    Q.pop();
    for (int y : g[x]) {
      if (~d[y]) continue;
      d[y] = d[x] + 1;
      Q.push(y);
    }
  }
  for (int i = 1; i <= n; i++)
    if (~d[i]) f[S][d[i]].set(i);
  for (int i = 1; i <= n; i++) f[S][i] |= f[S][i - 1];
}
int main() {
  n = read(), m = read(), q = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    g[x].emplace_back(y), g[y].emplace_back(x);
  }
  for (int i = 1; i <= n; i++) bfs(i);
  while (q--) {
    int ans = 0;
    bitset<N> t;
    for (int num = read(); num; num--) {
      int x = read(), y = read();
      t |= f[x][y];
    }
    write(t.count()), pc('\n');
  }
  fsh();
}
