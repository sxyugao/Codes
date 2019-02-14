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
int main() {
  int lst = 0, ans = 0, remain = 0;
  for (int n = read(); n; n--) {
    int t = read(), c = read();
    remain -= t - lst;
    remain = max(remain, 0);
    lst = t;
    remain += c;
    ans = max(ans, remain);
  }
  printf("%d %d", lst + remain, ans);
}