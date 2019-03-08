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
struct Data {
  int s, t;
  bool operator<(const Data &b) const {
    if (t != b.t) return t < b.t;
    return s < b.s;
  }
  void input() { s = read(), t = read(); }
} a[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i].input();
  sort(a + 1, a + n + 1);
  int lst = 0, ans = 0;
  for (int i = 1; i <= n; i++)
    if (lst <= a[i].s) {
      ans++, lst = a[i].t;
    }
  printf("%d", ans);
}