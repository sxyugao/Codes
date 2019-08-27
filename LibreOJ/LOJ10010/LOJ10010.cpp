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
const int N = 1e6 + 5;
long long Abs(long long x) { return x < 0 ? -x : x; }
int a[N], b[N];
int main() {
  int n = read();
  long long ave = 0;
  for (int i = 1; i <= n; i++) ave += a[i] = read();
  ave /= n;
  for (int i = 1; i <= n; i++) b[i] = b[i - 1] - a[i] + ave;
  sort(b + 1, b + n + 1);
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += Abs(b[i] - b[(n + 1) / 2]);
  printf("%lld", ans);
}
