#include <cstdio>
#include <iostream>
using namespace std;
char gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const int N = 2e5 + 5;
int a[N];
int main() {
  for (int T = read(); T; --T) {
    int n = read(), x = read(), pos = 0;
    for (int i = 1; i <= n; ++i) {
      a[i] = read();
      if (a[i] == x) pos = i;
    }
    int l = 1, r = n + 1;
    while (r - l > 1) {
      int m = (l + r) / 2;
      if (a[m] <= x)
        l = m;
      else
        r = m;
    }
    printf("1\n%d %d\n", l, pos);
  }
}