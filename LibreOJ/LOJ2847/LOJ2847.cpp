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
int top, a[N], r[N], R[N], stk[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  stk[0] = n + 1;
  for (int i = n; i; i--) {
    while (top && a[stk[top]] >= a[i]) top--;
    R[i] = stk[top], stk[++top] = i;
  }
  top = 0;
  for (int i = n; i; i--) {
    while (top && a[stk[top]] < a[i]) top--;
    r[i] = stk[top], stk[++top] = i;
  }
  int ans = 0;
  for (int i = 1, j; i <= n; i = j + 1) {
    j = i;
    ans++;
    while (r[j] < R[i]) j = r[j];
  }
  printf("%d", ans);
}
