#include <cstdio>
#include <iostream>
using namespace std;
const int N = 3e4;
int n, x, y, f[N + 5], d[N + 5], h[N + 5];
char opt[1];
int Find(int x) {
  if (f[x] == x) return x;
  int fa = f[x];
  f[x] = Find(f[x]);
  d[x] += d[fa];
  return f[x];
}
int main() {
  for (int i = 1; i <= N; i++) f[i] = i, d[i] = 0, h[i] = 1;
  scanf("%d", &n);
  while (n--) {
    scanf("%s", opt);
    if (*opt == 'M') {
      scanf("%d%d", &x, &y);
      x = Find(x), y = Find(y);
      f[x] = y;
      d[x] = h[y];
      h[y] += h[x];
    } else {
      scanf("%d", &x);
      Find(x);
      printf("%d\n", d[x]);
    }
  }
}
