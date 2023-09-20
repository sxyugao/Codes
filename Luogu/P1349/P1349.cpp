#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
LL p, q, a1, a2, n, m;
struct matrix {
  int n, m;
  LL a[2][2];
  matrix() { memset(a, 0, sizeof(a)); }
};
matrix mul(matrix a, matrix b) {
  matrix c;
  c.n = a.n, c.m = b.m;
  for (int i = 0; i < a.n; ++i)
    for (int j = 0; j < b.m; ++j)
      for (int k = 0; k < a.m; ++k) {
        c.a[i][j] += a.a[i][k] * b.a[k][j];
        c.a[i][j] %= m;
      }
  return c;
}
int main() {
  cin >> p >> q >> a1 >> a2 >> n >> m;
  if (n == 1) return cout << a1 % m, 0;
  if (n == 2) return cout << a2 % m, 0;
  matrix a;
  a.n = 1, a.m = 2;
  a.a[0][0] = a1 % m, a.a[0][1] = a2 % m;
  matrix b;
  b.n = b.m = 2;
  b.a[0][0] = 0, b.a[0][1] = q;
  b.a[1][0] = 1, b.a[1][1] = p;
  n -= 2;
  while (n) {
    if (n & 1) a = mul(a, b);
    b = mul(b, b);
    n >>= 1;
  }
  cout << a.a[0][1];
}