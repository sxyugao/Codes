#include <cstdio>
#include <cstring>
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
const int N = 1e5 + 5;
int head[N];
struct Edge {
  int to, nxt;
} edge[N];
int deg[N];
int siz, a[N];
void init() {
  memset(head, 0, sizeof(head));
  memset(edge, 0, sizeof(edge));
  memset(deg, 0, sizeof(deg));
  siz = 0;
}
int main() {
  for (int T = read(); T; T--) {
    init();
    int n = read();
    for (int m = read(); m; m--) {
      int x = read(), y = read();
      edge[m].to = x;
      edge[m].nxt = head[y];
      head[y] = m;
      deg[x]++;
    }
    priority_queue<int> q;
    for (int i = 1; i <= n; i++)
      if (!deg[i]) q.push(i);
    while (!q.empty()) {
      int x = q.top();
      q.pop();
      a[++siz] = x;
      for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        deg[y]--;
        if (!deg[y]) q.push(y);
      }
    }
    if (siz < n) {
      puts("Impossible!");
    } else {
      for (int i = siz; i; i--) printf("%d ", a[i]);
      puts("");
    }
  }
}