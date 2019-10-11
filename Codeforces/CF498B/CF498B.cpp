#include <cmath>
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
double p[N], f[N][N];
int t[N];
int main() {
  int n = read(), T = read();
  for (int i = 1; i <= n; i++) {
    p[i] = 1.0 * read() / 100;
    t[i] = read();
  }
  double ans = 0;
  f[0][0] = 1;
  for (int i = 1; i <= n; i++) {
    double sum = 0;
    double lst = pow(1 - p[i], t[i] - 1);
    for (int j = 1; j <= T; j++) {
      sum *= 1 - p[i];
      sum += f[i - 1][j - 1] * p[i];
      if (j >= t[i]) {
        sum -= f[i - 1][j - t[i]] * lst * p[i];
        f[i][j] += f[i - 1][j - t[i]] * lst;
      }
      f[i][j] += sum;
      ans += f[i][j];
    }
  }
  printf("%.9lf", ans);
}
