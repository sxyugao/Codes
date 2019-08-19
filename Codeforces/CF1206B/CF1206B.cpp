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
int a[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int cnt1 = 0, cnt2 = 0;
  long long ans = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] < 0) {
      ans += -1 - a[i];
      cnt1++;
    } else {
      if (a[i] == 0) {
        cnt2++;
      } else {
        ans += a[i] - 1;
      }
    }
  if (cnt1 & 1 && !cnt2) ans += 2;
  printf("%lld", ans + cnt2);
}
