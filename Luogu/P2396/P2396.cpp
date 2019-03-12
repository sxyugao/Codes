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
const int P = 1e9 + 7;
int a[2], f[1 << 24], sum[1 << 24];
inline int lowbit(int x) { return x & -x; }
inline void Add(int &x, int y) { x = x + y >= P ? x + y - P : x + y; }
int main() {
  int n = read();
  for (register int i = 0; i < n; i++) sum[1 << i] = read();
  int m = read();
  for (register int i = 0; i < m; i++) a[i] = read();
  f[0] = 1;
  for (register int i = 1; i < (1 << n); i++) {
    int tmp = lowbit(i);
    sum[i] = sum[i ^ tmp] + sum[tmp];
    if (sum[i] == a[0] || sum[i] == a[1]) continue;
    for (register int j = i; j; j -= lowbit(j)) Add(f[i], f[i ^ lowbit(j)]);
  }
  printf("%d", f[(1 << n) - 1]);
}