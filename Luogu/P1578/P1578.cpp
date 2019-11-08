#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 5005;
struct Data {
  int x, y;
  void input() { x = read(), y = read(); }
  bool operator<(const Data &b) const {
    if (x != b.x) return x < b.x;
    return y < b.y;
  }
} a[N];
bool cmp(Data a, Data b) { return a.y < b.y; }
int main() {
  int L = read(), W = read(), n = read();
  for (int i = 1; i <= n; i++) a[i].input();
  a[++n] = {0, 0}, a[++n] = {0, W}, a[++n] = {L, 0}, a[++n] = {L, W};
  sort(a + 1, a + n + 1);
  int x1, y1, x2, y2, ans = 0;
  for (int i = 1; i <= n; i++) {
    x1 = a[i].x, y1 = 0, y2 = W;
    for (int j = i + 1; j <= n; j++) {
      x2 = a[j].x;
      ans = max(ans, (x2 - x1) * (y2 - y1));
      (a[j].y > a[i].y) ? y2 = min(y2, a[j].y) : y1 = max(y1, a[j].y);
    }
  }
  for (int i = n; i; i--) {
    x2 = a[i].x, y1 = 0, y2 = W;
    for (int j = i - 1; j; j--) {
      x1 = a[j].x;
      ans = max(ans, (x2 - x1) * (y2 - y1));
      (a[j].y > a[i].y) ? y2 = min(y2, a[j].y) : y1 = max(y1, a[j].y);
    }
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 2; i <= n; i++) ans = max(ans, (a[i].y - a[i - 1].y) * L);
  printf("%d", ans);
}
