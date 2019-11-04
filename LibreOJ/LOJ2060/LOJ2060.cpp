#include <cstdio>
#include <iostream>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 1e5 + 5;
int head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
int f[N], in[N], out[N];
int dfs(int x) {
  if (f[x]) return f[x];
  if (!in[x]) return 1;
  for (int i = head[x]; i; i = edge[i].nxt)
    f[x] += dfs(edge[i].to);
  return f[x];
}
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    edge[i].to = x;
    edge[i].nxt = head[y];
    head[y] = i;
    out[x]++, in[y]++;
  }
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (!out[i]) dfs(i), ans += f[i];
  printf("%d", ans);
}
