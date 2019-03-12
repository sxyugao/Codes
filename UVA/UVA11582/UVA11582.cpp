#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
#define gc c = getchar()
ull read() {
  ull x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
int pw(int a, ull n, int P) {
  if (a == 0) return 0;
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return ans;
}
int f[1005][7005], g[1005];
void init() {
  g[1] = 1;
  for (int i = 2; i <= 1000; i++) {
    f[i][0] = 0;
    f[i][1] = 1;
    for (int j = 2;; j++) {
      f[i][j] = (f[i][j - 1] + f[i][j - 2]) % i;
      if (f[i][j - 1] == 0 && f[i][j] == 1) {
        g[i] = j - 1;
        break;
      }
    }
  }
}
int main() {
  init();
  for (int T = read(); T; T--) {
    ull a = read(), b = read();
    int n = read();
    printf("%d\n", f[n][pw(a % g[n], b, g[n])] % n);
  }
}