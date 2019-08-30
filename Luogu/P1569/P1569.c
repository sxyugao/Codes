#include <stdio.h>
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; c < '0' || c > '9'; gc)
    if (c == '-') f = -1;
  for (; '0' <= c && c <= '9'; gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
#define max(a, b) ((a) > (b) ? (a) : (b))
int n, f[1005], a[1005];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = a[i - 1] + read();
  f[0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      if (a[i] - a[j - 1] >= 0 && f[j - 1]) f[i] = max(f[i], f[j - 1] + 1);
  if (!f[n]) return puts("Impossible"), 0;
  printf("%d", f[n] - 1);
}