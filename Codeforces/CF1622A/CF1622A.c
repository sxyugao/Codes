#include <stdio.h>
int chk(int a, int b, int c) {
  if (a + b == c) return 1;
  if (a == b && c % 2 == 0) return 1;
  return 0;
}
int main() {
  int T, a, b, c;
  scanf("%d", &T);
  while (T--) {
    scanf("%d%d%d", &a, &b, &c);
    puts((chk(a, b, c) || chk(a, c, b) || chk(b, c, a)) ? "YES" : "NO");
  }
}