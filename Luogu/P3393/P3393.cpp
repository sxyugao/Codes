#include <bits/stdc++.h>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e6 + 5;
struct e {
  int x, y;
} e[N << 1];
int nedge, head[N];
struct edge {
  int to, nxt;
  long long w;
} edge[N << 1];
void add(int x, int y, long long z) {
  edge[++nedge].to = y;
  edge[nedge].w = z;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
struct Data {
  int x;
  long long d;
  bool operator<(const Data &b) const { return d > b.d; }
};
bool vis[N];
long long a[N], d[N];
int main() {
  int n = read(), m = read(), k = read(), s = read() + 1;
  int P = read(), Q = read();
  queue<int> que;
  for (int i = 1; i <= k; i++) {
    int x = read();
    que.push(x);
    d[x] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    e[i].x = x, e[i].y = y;
    add(x, y, 0), add(y, x, 0);
  }
  while (!que.empty()) {
    int x = que.front();
    que.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      if (d[y]) continue;
      d[y] = d[x] + 1;
      que.push(y);
    }
  }
  for (int i = 2; i < n; i++) {
    if (d[i] == 1) {
      a[i] = 1e18;
    } else {
      a[i] = d[i] <= s ? Q : P;
    }
  }
  nedge = 0;
  memset(head, 0, sizeof(head));
  for (int i = 1; i <= m; i++) {
    add(e[i].x, e[i].y, a[e[i].x] + a[e[i].y]);
    add(e[i].y, e[i].x, a[e[i].x] + a[e[i].y]);
  }
  memset(d, 0x3f, sizeof(d));
  priority_queue<Data> q;
  d[1] = 0;
  q.push(Data{1, 0});
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
  printf("%lld", d[n] / 2);
}