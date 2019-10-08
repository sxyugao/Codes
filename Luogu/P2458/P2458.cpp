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
const int N = 1505;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
int rt, a[N], in[N], f[N][3];
// 0 父亲 1 儿子 2 自己
void dfs(int x) {
  int s1 = 0, s2 = 0;
  // s1 给 f[x][2]，s2 给 f[x][1] 和 f[x][0]
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    dfs(y);
    s1 += min(f[y][0], min(f[y][1], f[y][2]));
    s2 += min(f[y][1], f[y][2]);
  }
  f[x][0] = s2;
  f[x][1] = 1e9;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    f[x][1] = min(f[x][1], s2 - min(f[y][1], f[y][2]) + f[y][2]);
  }
  f[x][2] = s1 + a[x];
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int id = read();
    a[id] = read();
    int m = read();
    while (m--) {
      int x = read();
      in[x]++;
      edge[++nedge].to = x;
      edge[nedge].nxt = head[id];
      head[id] = nedge;
    }
  }
  for (int i = 1; i <= n; i++)
    if (!in[i]) {
      rt = i;
      break;
    }
  dfs(rt);
  printf("%d", min(f[rt][1], f[rt][2]));
}
