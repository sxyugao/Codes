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
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 3e5 + 5;
int a[N], mn[30][N], mx[30][N];
inline int chkmn(int x, int y) {
  if (a[x] <= a[y]) return x;
  return y;
}
inline int chkmx(int x, int y) {
  if (a[x] > a[y]) return x;
  return y;
}
inline int askmn(int l, int r) {
  int k = log2(r - l + 1);
  return chkmn(mn[k][l], mn[k][r - (1 << k) + 1]);
}
inline int askmx(int l, int r) {
  int k = log2(r - l + 1);
  return chkmx(mx[k][l], mx[k][r - (1 << k) + 1]);
}
int solve(int l, int r) {
  if (l > r) return 0;
  int x1 = askmn(l, r);
  int x2 = askmx(x1, r);
  return solve(l, x1 - 1) + solve(x2 + 1, r) + 1;
}
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++) mn[0][i] = mx[0][i] = i;
  for (int j = 1; 1 << j <= n; j++)
    for (int i = 1; i + (1 << j) - 1 <= n; i++) {
      mn[j][i] = chkmn(mn[j - 1][i], mn[j - 1][i + (1 << (j - 1))]);
      mx[j][i] = chkmx(mx[j - 1][i], mx[j - 1][i + (1 << (j - 1))]);
    }
  printf("%d", solve(1, n));
}
