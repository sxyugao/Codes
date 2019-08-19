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
int main() {
  int n = read(), mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, read());
  printf("%d ", mx);
  n = read(), mx = 0;
  for (int i = 1; i <= n; i++) mx = max(mx, read());
  printf("%d", mx);
}
