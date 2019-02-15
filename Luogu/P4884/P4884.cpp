#include <cmath>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
LL k, m;
unordered_map<LL, LL> Hash;
LL mul(LL a, LL b, LL P) {
  LL L = a * (b >> 25LL) % P * (1LL << 25) % P;
  LL R = a * (b & ((1LL << 25) - 1)) % P;
  return (L + R) % P;
}
LL pw(LL a, LL n, LL P) {
  LL ans = 1;
  while (n) {
    if (n & 1) ans = mul(ans, a, P);
    a = mul(a, a, P);
    n >>= 1;
  }
  return ans;
}
LL BSGS(LL a, LL b, LL P) {
  LL len = ceil(sqrt(P));
  for (LL i = 0; i < len; i++) Hash[mul(b, pw(a, i, P), P)] = i;
  a = pw(a, len, P);
  for (LL i = 0; i <= len; i++) {
    LL x = pw(a, i, P);
    LL j = Hash.count(x) ? Hash[x] : -1;
    if (j >= 0 && i * len - j >= 0) return i * len - j;
  }
  return -1;
}
int main() {
  scanf("%lld%lld", &k, &m);
  k = k * 9 + 1;
  k %= m;
  printf("%lld", BSGS(10, k, m));
}