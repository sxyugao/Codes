#include <stdio.h>
int n, x, ans, a[100005];
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d", &x);
    if (a[x]) ans++;
    a[x]++;
  }
  printf("%d\n", ans);
}
