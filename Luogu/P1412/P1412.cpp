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
const int N = 1e5 + 5;
int a[N], b[N];
int main() {
  int n = read(), k = read(), c = read(), w = read();
  double x = 1 - 1.0 * k / 100, y = 1 + 1.0 * c / 100;
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read();
  double ans = 0;
  for (int i = n; i; i--) {
    if (a[i] == 1) ans = max(ans, b[i] + ans * x);
    if (a[i] == 2) ans = max(ans, -b[i] + ans * y);
  }
  printf("%.2lf", ans * w);
}
