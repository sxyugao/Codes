#include <cstdio>
typedef long long LL;
const int N = 2e5 + 5;
char buf[1 << 14], *p = buf;
void pc(char c) {
  if (buf + (1 << 14) == p) {
    fwrite(buf, 1, 1 << 14, stdout);
    p = buf;
  }
  *p++ = c;
}
template <class T>
void write(T x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
template <class T>
void writeln(T x) {
  write(x), pc('\n');
}
void fsh() {
  fwrite(buf, 1, p - buf, stdout);
}
LL sqr(LL x) { return x * x; }
int a, b, x;
int main() {
  scanf("%d%d", &a, &b);
  if (!a) {
    writeln(-sqr(b));
    for (int i = 1; i <= b; i++) pc('x');
  } else if (!b) {
    writeln(sqr(a));
    for (int i = 1; i <= a; i++) pc('o');
  } else if (b == 1) {
    writeln(sqr(a) - 1);
    for (int i = 1; i <= a; i++) pc('o');
    pc('x');
  } else {
    LL ans = -1e18;
    for (int i = 2; i <= a + 1 && i <= b; i++) {
      int len = b / i, rest = b % i;
      LL tmp = i - 2 + sqr(a - (i - 2)) - sqr(len) * (i - rest) - sqr(len + 1) * rest;
      if (tmp > ans) ans = tmp, x = i;
    }
    writeln(ans);
    int len = b / x, rest = b % x;
    for (int i = 1; i < x; i++) {
      for (int j = 1; j <= len + (i > x - rest); j++) pc('x');
      pc('o');
      if (i == x - 1)
        for (int j = 1; j < a - (x - 2); j++) pc('o');
    }
    for (int i = 1; i <= len + bool(rest); i++) pc('x');
  }
  fsh();
}
