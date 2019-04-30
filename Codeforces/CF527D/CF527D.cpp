#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
struct Data {
  int l, r;
  bool operator<(const Data &b) const {
    if (r != b.r) return r < b.r;
    return l < b.l;
  }
} a[200000];
int n, x, w;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &x, &w);
    a[i].l = x - w, a[i].r = x + w;
  }
  sort(a, a + n);
  int lst = -0x7fffffff, ans = 0;
  for (int i = 0; i < n; i++)
    if (lst <= a[i].l) {
      ans++;
      lst = a[i].r;
    }
  printf("%d", ans);
}