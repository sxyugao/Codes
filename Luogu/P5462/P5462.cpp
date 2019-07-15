#include <cstdio>
#include <iostream>
#include <set>
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
const int N = 1e5 + 5;
set<int> s;
int a[N], p[N], l[N], r[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) l[i] = i - 1, r[i] = i + 1;
  for (int i = 1; i <= n; i++) {
    a[i] = read();
    p[a[i]] = i;
    s.insert(a[i]);
  }
  while (s.size()) {
    int x = *s.rbegin();
    s.erase(*s.rbegin());
    int px = p[x], py = r[px];
    if (py > n) continue;
    printf("%d %d ", x, a[py]);
    s.erase(a[py]);
    r[l[px]] = r[py];
    l[r[py]] = l[px];
  }
}
