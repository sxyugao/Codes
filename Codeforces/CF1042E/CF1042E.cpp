#include <algorithm>
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
const int N = 1005;
const int P = 998244353;
int pw(int a, int n) {
  int ans = 1;
  while (n) {
    if (n & 1) ans = 1LL * ans * a % P;
    a = 1LL * a * a % P;
    n >>= 1;
  }
  return ans;
}
void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
int sqr(int x) { return 1LL * x * x % P; }
struct Data {
  int x, y, z;
  bool operator<(const Data &b) const {
    return z < b.z;
  }
} a[N * N];
int f[N * N];
int main() {
  int n = read(), m = read();
  int num = n * m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      a[m * (i - 1) + j].x = i, a[m * (i - 1) + j].y = j;
      a[m * (i - 1) + j].z = read();
    }
  int x = read(), y = read();
  sort(a + 1, a + num + 1);
  int sumx = 0, sumy = 0, sump = 0, sum = 0;
  int lst = 1;
  for (int i = 1; i <= num; i++) {
    if (a[i].z != a[lst].z) {
      for (; lst < i; lst++) {
        Add(sumx, a[lst].x);
        Add(sumy, a[lst].y);
        Add(sump, sqr(a[lst].x));
        Add(sump, sqr(a[lst].y));
        Add(sum, f[lst]);
      }
    }
    int p = lst - 1;
    Add(f[i], 1LL * p * sqr(a[i].x) % P);
    Add(f[i], 1LL * p * sqr(a[i].y) % P);
    Add(f[i], P - 2LL * a[i].x * sumx % P);
    Add(f[i], P - 2LL * a[i].y * sumy % P);
    Add(f[i], sump);
    Add(f[i], sum);
    f[i] = 1LL * f[i] * pw(p, P - 2) % P;
    if (a[i].x == x && a[i].y == y) return printf("%d", f[i]), 0;
  }
}
