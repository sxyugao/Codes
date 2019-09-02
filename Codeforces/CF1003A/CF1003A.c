#include <stdio.h>
#define max(a, b) (a > b ? a : b)
int n, x, cnt[105];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x), cnt[x]++;
  int mx = 0;
  for (int i = 1; i <= 100; i++) mx = max(mx, cnt[i]);
  printf("%d", mx);
}
