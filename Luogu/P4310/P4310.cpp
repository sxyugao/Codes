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
int f[35];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    int x = read();
    int mx = 1;
    for (int j = 0; j <= 30; j++)
      if (x & (1 << j)) mx = max(mx, f[j] + 1);
    for (int j = 0; j <= 30; j++)
      if (x & (1 << j)) f[j] = max(f[j], mx);
  }
  int ans = 0;
  for (int i = 1; i <= 32; i++) ans = max(ans, f[i]);
  printf("%d", ans);
}
