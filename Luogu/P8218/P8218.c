#include <stdio.h>
char buf[1 << 14], *p1 = buf, *p2 = buf;
char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
int n, l, r, sum[100005];
int main() {
  n = read();
  for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + read();
  n = read();
  while (n--) {
    l = read(), r = read();
    printf("%d\n", sum[r] - sum[l - 1]);
  }
}