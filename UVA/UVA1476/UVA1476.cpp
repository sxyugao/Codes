#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
const double eps = 1e-10;
int n, a[N], b[N], c[N];
double f(double x) {
  double ans = -1e18;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, a[i] * x * x + b[i] * x + c[i]);
  }
  return ans;
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", a + i, b + i, c + i);
    double l = 0, r = 1000;
    while (l + eps < r) {
      double mid = (l + r) / 2;
      if (f(mid) > f(mid + eps)) {
        l = mid;
      } else {
        r = mid;
      }
    }
    printf("%.4lf\n", f(l));
  }
}