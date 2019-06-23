#include <bitset>
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
bitset<10005> a[55];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int num = read(); num; num--)
      a[i].set(read());
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (!((a[i] & a[j]).count())) return puts("impossible"), 0;
  puts("possible");
}