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
const int N = 5e4 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, k;
long long ans, f[N][505];
void dfs(int x, int fa) {
  f[x][0] = 1;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    dfs(y, x);
    for (int j = 1; j <= k; j++) f[x][j] += f[y][j - 1];
  }
  long long sum = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa) continue;
    for (int j = 1; j < k; j++)
      sum += (f[x][j] - f[y][j - 1]) * f[y][k - j - 1];
  }
  ans += sum / 2 + f[x][k];
}
int main() {
  n = read(), k = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  printf("%lld", ans);
}