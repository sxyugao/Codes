#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline LL read() {
  LL x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
LL gcd(LL a, LL b) {
  return b ? gcd(b, a % b) : a;
}
inline LL GCD(LL a, LL b) {
  for (int i = 2; i <= 7; i++)
    if (a % i == 0 && b % i == 0) return i;
  return gcd(a, b);
}
int main() {
  for (int T = read(); T; T--) {
    LL p = read(), q = read(), b = read();
    LL g = gcd(p, q);
    p /= g, q /= g;
    do {
      g = GCD(b, q);
      q /= g;
    } while (g > 1);
    puts(q ^ 1 ? "Infinite" : "Finite");
  }
}
