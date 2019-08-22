#include <algorithm>
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
const int N = 2e5 + 5;
struct Data {
  int x, y, id;
  bool operator<(const Data &b) const {
    return x < b.x;
  }
  void input(int p) {
    x = read(), y = read(), id = p;
  }
} a[N << 1];
int n, m, f[25][N << 1], ans[N];
inline int query(int S) {
  int T = a[S].x + m, ans = 0;
  for (int i = 20; ~i; i--)
    if (a[f[i][S]].y < T) {
      ans += 1 << i;
      S = f[i][S];
    }
  return ans + 2;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    a[i].input(i);
    if (a[i].x > a[i].y) a[i].y += m;
    a[n + i] = a[i];
    a[n + i].x += m;
    a[n + i].y += m;
  }
  sort(a + 1, a + n * 2 + 1);
  for (int i = 2 * n; i; i--) {
    f[0][i] = upper_bound(a + 1, a + 2 * n + 1, Data{a[i].y, 0, 0}) - a - 1;
    for (int j = 1; j <= 20; j++) f[j][i] = f[j - 1][f[j - 1][i]];
  }
  for (int i = 1; i <= n; i++) ans[a[i].id] = query(i);
  for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}
