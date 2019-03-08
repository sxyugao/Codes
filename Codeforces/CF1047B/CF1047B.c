#include <stdio.h>
#define max(a, b) ((a) > (b) ? (a) : (b))
int n, x, y, ans;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &x, &y);
    ans = max(ans, x + y);
  }
  printf("%d", ans);
}