#include <algorithm>
#include <cmath>
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
struct Data {
  int x, y, z;
  void input() { x = read(), y = read(), z = read(); }
  bool operator<(const Data &b) const { return z < b.z; }
} a[50005];
double sqr(double x) { return x * x; }
double dist(Data a, Data b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i].input();
  sort(a + 1, a + n + 1);
  double ans = 0;
  for (int i = 2; i <= n; i++) ans += dist(a[i], a[i - 1]);
  printf("%.3lf", ans);
}