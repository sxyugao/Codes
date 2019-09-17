#include <stdio.h>
#define N 200005
int n, x[N], y[N];
char a[N], b[N];
int main() {
  scanf("%d\n", &n);
  gets(a + 1), gets(b + 1);
  for (int i = 1; i <= n; i++)
    if (a[i] ^ b[i]) {
      if (a[i] == 'a') x[++*x] = i;
      if (a[i] == 'b') y[++*y] = i;
    }
  if ((*x + *y) & 1) return puts("-1"), 0;
  printf("%d\n", *x / 2 + *y / 2 + ((*x & 1) ? 2 : 0));
  for (int i = 1; i < *x; i += 2) printf("%d %d\n", x[i], x[i + 1]);
  for (int i = 1; i < *y; i += 2) printf("%d %d\n", y[i], y[i + 1]);
  if (*x & 1) {
    printf("%d %d\n", x[*x], x[*x]);
    printf("%d %d\n", x[*x], y[*y]);
  }
}
