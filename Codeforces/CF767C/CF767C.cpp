#include <cstdio>
#include <iostream>
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
const int N = 1e6 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N];
int rt, cnt, sum, a[N], v[N];
void dfs(int x) {
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    dfs(y);
    a[x] += a[y];
  }
  if (a[x] == sum && x != rt) v[cnt++] = x, a[x] = 0;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    if (!x) {
      rt = i;
    } else {
      edge[++nedge].to = i;
      edge[nedge].nxt = head[x];
      head[x] = nedge;
    }
    sum += a[i] = read();
  }
  if (sum % 3) return puts("-1"), 0;
  sum /= 3;
  dfs(rt);
  if (cnt < 2) return puts("-1"), 0;
  printf("%d %d", v[0], v[1]);
}
