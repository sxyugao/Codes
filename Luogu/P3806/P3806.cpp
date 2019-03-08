#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e4 + 5;
const int INF = 1e9;
int n, m, q[N];
int nedge, head[N];
struct Edge {
  int to, nxt, w;
} edge[N << 1];
void add(int x, int y, int z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int rt, sum, siz[N], mx[N];
bool vis[N];
void getrt(int x, int fa) {
  siz[x] = 1, mx[x] = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa || vis[y]) continue;
    getrt(y, x);
    siz[x] += siz[y];
    mx[x] = max(mx[x], siz[y]);
  }
  mx[x] = max(mx[x], sum - siz[x]);
  if (mx[x] < mx[rt]) rt = x;
}
int cnt, a[N], tmp[N], dis[N];
void getdis(int x, int fa) {
  a[++cnt] = dis[x];
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa || vis[y]) continue;
    dis[y] = dis[x] + edge[i].w;
    getdis(y, x);
  }
}
bool ans[N], hasdis[10000005];
void getans(int x) {
  int num = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (vis[y]) continue;
    cnt = 0;
    dis[y] = edge[i].w;
    getdis(y, x);
    for (int j = 1; j <= cnt; j++)
      for (int k = 1; k <= m; k++)
        if (q[k] >= a[j]) ans[k] |= hasdis[q[k] - a[j]];
    for (int j = 1; j <= cnt; j++) {
      tmp[++num] = a[j];
      hasdis[a[j]] = 1;
    }
  }
  for (int i = 1; i <= num; i++) hasdis[tmp[i]] = 0;
}
void solve(int x) {
  vis[x] = hasdis[0] = 1;
  getans(x);
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (vis[y]) continue;
    sum = siz[y], mx[rt = 0] = INF;
    getrt(y, 0), solve(rt);
  }
}
int main() {
  n = read(), m = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read(), z = read();
    add(x, y, z), add(y, x, z);
  }
  for (int i = 1; i <= m; i++) q[i] = read();
  sum = mx[0] = n;
  getrt(1, 0);
  solve(rt);
  for (int i = 1; i <= m; i++) puts(ans[i] ? "AYE" : "NAY");
}