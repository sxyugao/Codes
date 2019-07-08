#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
typedef long long LL;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
#define gc c = _gc()
LL read() {
  LL x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e5 + 5;
LL A[N], B[N], D[N], E[N], f[N];
int tmp[10];
multiset<LL> g[N], ans;
int main() {
  int n = read(), q = read();
  for (int i = 1; i <= n; i++) B[i] = read(), D[i] = 2;
  for (int i = 1; i <= n; i++) A[i] = read(), D[A[i]]++;
  for (int i = 1; i <= n; i++) E[i] = B[i] / D[i];
  for (int i = 1; i <= n; i++) f[A[i]] += E[i];
  for (int i = 1; i <= n; i++) f[i] += E[i] + B[i] % D[i];
  for (int i = 1; i <= n; i++) g[A[i]].insert(f[i]);
  for (int i = 1; i <= n; i++)
    if (g[i].size()) {
      ans.insert(E[i] + *g[i].begin());
      ans.insert(E[i] + *(--g[i].end()));
    }
  while (q--) {
    int opt = read();
    if (opt == 1) {
      int x = read(), y = read();
      if (A[x] == y) continue;
      tmp[0] = x, tmp[1] = A[x], tmp[2] = A[A[x]], tmp[3] = A[A[A[x]]];
      tmp[4] = y, tmp[5] = A[y], tmp[6] = A[A[y]];
      sort(tmp, tmp + 7);
      for (int i = 0; i < 7; i++) {
        if (tmp[i] == tmp[i + 1]) continue;
        int x = tmp[i];
        if (g[x].size()) {
          ans.erase(ans.find(E[x] + *g[x].begin()));
          ans.erase(ans.find(E[x] + *(--g[x].end())));
        }
      }
      g[A[A[A[x]]]].erase(g[A[A[A[x]]]].find(f[A[A[x]]]));
      f[A[A[x]]] = f[A[A[x]]] - E[A[x]] + B[A[x]] / (D[A[x]] - 1);
      g[A[A[A[x]]]].insert(f[A[A[x]]]);
      g[A[A[x]]].erase(g[A[A[x]]].find(f[A[x]]));
      f[A[x]] = f[A[x]] - E[x] - (E[A[x]] + B[A[x]] % D[A[x]]) +
                B[A[x]] / (D[A[x]] - 1) + B[A[x]] % (D[A[x]] - 1);
      g[A[A[x]]].insert(f[A[x]]);
      g[A[x]].erase(g[A[x]].find(f[x]));
      g[y].insert(f[x]);
      g[A[A[y]]].erase(g[A[A[y]]].find(f[A[y]]));
      f[A[y]] = f[A[y]] - E[y] + B[y] / (D[y] + 1);
      g[A[A[y]]].insert(f[A[y]]);
      g[A[y]].erase(g[A[y]].find(f[y]));
      f[y] = f[y] - (E[y] + B[y] % D[y]) + B[y] / (D[y] + 1) +
             B[y] % (D[y] + 1) + E[x];
      g[A[y]].insert(f[y]);
      D[A[x]]--, D[y]++;
      E[A[x]] = B[A[x]] / D[A[x]], E[y] = B[y] / D[y];
      for (int i = 0; i < 7; i++) {
        int x = tmp[i];
        if (tmp[i] == tmp[i + 1]) continue;
        if (g[x].size()) {
          ans.insert(E[x] + *g[x].begin());
          ans.insert(E[x] + *(--g[x].end()));
        }
      }
      A[x] = y;
    }
    if (opt == 2) {
      int x = read();
      printf("%lld\n", f[x] + E[A[x]]);
    }
    if (opt == 3) printf("%lld %lld\n", *ans.begin(), *(--ans.end()));
  }
}
