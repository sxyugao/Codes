#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
LL gcd(LL x, LL y) { return y ? gcd(y, x % y) : x; }
LL lcm(LL x, LL y) { return 1LL * x * y / gcd(x, y); }
int main() {
  int n;
  scanf("%d", &n);
  if (n == 1) return puts("1"), 0;
  if (n == 2) return puts("2"), 0;
  if (n & 1) return printf("%lld", lcm(lcm(n, n - 1), n - 2)), 0;
  printf("%lld", max(lcm(lcm(n, n - 1), n - 3), lcm(lcm(n - 1, n - 2), n - 3)));
}