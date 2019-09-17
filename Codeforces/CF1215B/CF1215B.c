#include <stdio.h>
int read() {
  int x = 0, f = 1;
  char c = getchar();
  for (; !isdigit(c); c = getchar())
    if (c == '-') f = -1;
  for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
  return x * f;
}
int a, b;
long long ans1, ans2;
int main() {
  for (int n = read(); n; n--) {
    int x = read();
    if (x < 0) {
      int t = a;
      a = b;
      b = t;
      a++;
    } else {
      b++;
    }
    ans1 += a;
    ans2 += b;
  }
  printf("%lld %lld", ans1, ans2);
}
