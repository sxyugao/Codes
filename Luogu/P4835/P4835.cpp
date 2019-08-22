#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
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
int n, a[N], b[N];
struct Data {
  int x, y;
  void input() { x = read(), y = read(); }
  bool operator<(const Data &b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
} t[N];
bool check(int x) {
  priority_queue<int> q;
  int p = 1;
  for (int i = 1; i <= *a; i++) {
    for (; t[p].x < a[i] && p <= n; p++) q.push(t[p].y);
    for (int j = 1; j <= x && !q.empty(); j++) q.pop();
  }
  for (; p <= n; p++) q.push(t[p].y);
  for (int i = *b; i; i--)
    for (int j = 1; j <= x && !q.empty() && q.top() < b[i]; j++) q.pop();
  return q.empty();
}
int main() {
  *a = read(), *b = read(), n = read();
  for (int i = 1; i <= *a; i++) a[i] = read();
  for (int i = 1; i <= *b; i++) b[i] = read();
  for (int i = 1; i <= n; i++) t[i].input();
  sort(a + 1, a + *a + 1);
  sort(b + 1, b + *b + 1);
  sort(t + 1, t + n + 1);
  for (int i = 1; i <= n; i++)
    if (t[i].x >= a[*a] && t[i].y >= b[*b]) return puts("Impossible"), 0;
  int l = 1, r = n, ans = n;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid)) {
      ans = mid, r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  printf("%d", ans);
}
