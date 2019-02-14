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
int a[100005];
int main() {
  int n = read(), k = read(), sum = 0;
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= k; i++) sum += a[i];
  int ans = sum;
  for (int i = k + 1; i <= n; i++) {
    sum -= a[i - k] - a[i];
    ans = max(ans, sum);
  }
  printf("%d\n", ans);
}