#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
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
  int x, t;
  bool operator<(const Data &b) const { return t < b.t; }
  void input() { t = read(), x = read(); }
} a[N];
priority_queue<int> q;
int main() {
  int n = read(), ans = 0;
  for (int i = 1; i <= n; i++) a[i].input();
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    if ((int)q.size() < a[i].t) {
      q.push(-a[i].x);
      ans += a[i].x;
    } else {
      if (a[i].x > -q.top()) {
        ans += q.top();
        q.pop();
        ans += a[i].x;
        q.push(-a[i].x);
      }
    }
  }
  printf("%d", ans);
}