#include <cstdio>
#include <iostream>
#include <queue>
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
const int N = 105;
int head[N];
struct Edge {
  int to, nxt, a, b;
} edge[N * N];
int in[N];
bool f[N][N * N], g[N][N * N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    edge[i].a = read(), edge[i].b = read();
    edge[i].to = y;
    edge[i].nxt = head[x];
    head[x] = i;
    in[y]++;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i);
  f[1][0] = g[1][0] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      for (int l = edge[i].a; l <= 100 * n; l++)
        f[y][l] |= f[x][l - edge[i].a];
      for (int l = edge[i].b; l <= 100 * n; l++)
        g[y][l] |= g[x][l - edge[i].b];
      in[y]--;
      if (!in[y]) q.push(y);
    }
  }
  for (int i = 0; i <= 100 * n; i++)
    if (f[n][i] && g[n][i]) return printf("%d", i), 0;
  puts("IMPOSSIBLE");
}
