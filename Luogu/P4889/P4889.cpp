#include <cstdio>
#include <iostream>
#include <map>
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
map<int, int> cnt;
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    cnt[i + x]++;
    cnt[i - x]++;
  }
  long long ans = 0;
  for (auto x : cnt) ans += 1LL * x.second * (x.second - 1) / 2;
  printf("%lld", ans);
}
