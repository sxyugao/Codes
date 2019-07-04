#include <cstdio>
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    scanf("%d", &n);
    printf("%lld\n", 1LL * n * (n - (n != 1)));
  }
}