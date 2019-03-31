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
const int N = 2e7 + 5;
const int P = 19260817;
struct Edge {
  int v, nxt;
  bool vis;
};
struct Hash {
  int nedge, head[N];
  Edge edge[N];
  int siz;
  void add(int x) {
    siz++;
    int p = x % P;
    for (int i = head[p]; i; i = edge[i].nxt)
      if (edge[i].v == x) return (void)(edge[i].vis = 1);
    edge[++nedge].v = x;
    edge[nedge].vis = 1;
    head[p] = nedge;
  }
  void del(int x) {
    int p = x % P;
    siz--;
    for (int i = head[p]; i; i = edge[i].nxt)
      if (edge[i].v == x) return (void)(edge[i].vis = 0);
  }
  bool has(int x) {
    int p = x % P;
    for (int i = head[p]; i; i = edge[i].nxt)
      if (edge[i].v == x && edge[i].vis) return 1;
    return 0;
  }
} h;
int p = 1, a[N];
int main() {
  int n = read(), ans = 0;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    while (h.has(a[i])) h.del(a[p++]);
    h.add(a[i]);
    ans = max(ans, h.siz);
  }
  printf("%d", ans);
}