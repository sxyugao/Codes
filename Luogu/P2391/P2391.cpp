#include <cstdio>
#include <iostream>
using namespace std;
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 ^ '0');
}
void writeln(int x) {
  write(x);
  puts("");
}
const int N = 1e6 + 5;
int f[N], a[N];
int Find(int x) { return f[x] = f[x] == x ? x : Find(f[x]); }
int main() {
  int n, m, p, q;
  scanf("%d%d%d%d", &n, &m, &p, &q);
  for (int i = 1; i <= n; i++) f[i] = i;
  f[n + 1] = n + 1;
  for (int i = m; i; i--) {
    int l = (i * p + q) % n + 1, r = (i * q + p) % n + 1;
    if (l > r) swap(l, r);
    for (int j = Find(l); j <= r; j = Find(j + 1)) {
      a[j] = i;
      f[j] = j + 1;
    }
  }
  for (int i = 1; i <= n; i++) writeln(a[i]);
}