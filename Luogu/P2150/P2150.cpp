#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int pri[] = {0, 2, 3, 5, 7, 11, 13, 17, 19};
const int N = 505;
const int S = 1 << 8;
struct Data {
  int s, p;
  void init(int x) {
    for (int i = 1; i < 9; i++) {
      if (x % pri[i]) continue;
      s |= 1 << (i - 1);
      while (x % pri[i] == 0) x /= pri[i];
    }
    if (x > 1) p = x;
  }
  bool operator<(const Data &b) const {
    return p < b.p;
  }
} a[N];
int n, P;
inline void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
int f[S][S], g[2][S][S];
int main() {
  scanf("%d%d", &n, &P);
  for (int i = 1; i < n; i++) a[i].init(i + 1);
  sort(a + 1, a + n);
  f[0][0] = 1;
  for (int i = 1; i < n; i++) {
    if (!a[i].p || a[i].p ^ a[i - 1].p) {
      memcpy(g[0], f, sizeof(g[0]));
      memcpy(g[1], f, sizeof(g[1]));
    }
    for (int j = S - 1; ~j; j--)
      for (int k = S - 1; ~k; k--) {
        if (j & k) continue;
        if (!(a[i].s & k)) Add(g[0][j | a[i].s][k], g[0][j][k]);
        if (!(a[i].s & j)) Add(g[1][j][k | a[i].s], g[1][j][k]);
      }
    if (!a[i].p || a[i].p ^ a[i + 1].p) {
      for (int j = 0; j < S; j++)
        for (int k = 0; k < S; k++) {
          if (j & k) continue;
          f[j][k] = g[0][j][k] + g[1][j][k] - f[j][k];
          f[j][k] = (f[j][k] % P + P) % P;
        }
    }
  }
  int ans = 0;
  for (int i = 0; i < S; i++)
    for (int j = 0; j < S; j++)
      Add(ans, f[i][j]);
  printf("%d", ans);
}
