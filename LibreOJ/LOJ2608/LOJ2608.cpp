#include <cstdio>
#include <iostream>
using namespace std;
int n, m, k, x;
int pw(int a, int b) {
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % n;
    a = 1LL * a * a % n;
    b >>= 1;
  }
  return ans;
}
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &x);
  printf("%lld", (x + 1LL * m * pw(10, k) % n) % n);
}