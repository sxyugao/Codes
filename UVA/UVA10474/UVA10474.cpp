#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e4 + 5;
int T, n, m, x, a[N];
int main() {
  while (scanf("%d%d", &n, &m), n || m) {
    printf("CASE# %d:\n", ++T);
    for (int i = 1; i <= n; i++) scanf("%d", a + i);
    a[n + 1] = 0;
    sort(a + 1, a + n + 1);
    while (m--) {
      scanf("%d", &x);
      int p = lower_bound(a + 1, a + n + 1, x) - a;
      if (a[p] ^ x) {
        printf("%d not found\n", x);
      } else {
        printf("%d found at %d\n", x, p);
      }
    }
  }
}
