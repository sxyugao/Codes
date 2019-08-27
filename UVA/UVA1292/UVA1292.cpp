#include <cstdio>
#include <cstring>
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
const int N = 1505;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int n, f[N][2], fa[N];
void init() {
  nedge = 0;
  memset(head, 0, sizeof(head));
  memset(fa, 0, sizeof(fa));
}
void dfs(int x) {
  f[x][1] = 1, f[x][0] = 0;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == fa[x]) continue;
    dfs(y);
    f[x][0] += f[y][1];
    f[x][1] += min(f[y][1], f[y][0]);
  }
}
int main() {
  while (~scanf("%d", &n)) {
    init();
    for (int i = 1; i <= n; i++) {
      int x = read() + 1, num = read();
      while (num--) {
        int y = read() + 1;
        add(x, y), add(y, x);
        fa[y] = x;
      }
    }
    for (int i = 1; i <= n; i++)
      if (!fa[i]) dfs(i), printf("%d\n", min(f[i][0], f[i][1]));
  }
}
