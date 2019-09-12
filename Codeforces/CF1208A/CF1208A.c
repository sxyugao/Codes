#include <stdio.h>
int T, n, f[3];
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", f, f + 1, &n);
    f[2] = f[0] ^ f[1];
    printf("%d\n", f[n % 3]);
  }
}
