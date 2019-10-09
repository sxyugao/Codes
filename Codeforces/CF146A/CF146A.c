#include <stdio.h>
int n, a, b;
char c;
#define chk(x)                                      \
  {                                                 \
    scanf("%c", &c);                                \
    if (c != '4' && c != '7') return puts("NO"), 0; \
    x += c ^ '0';                                   \
  }
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n / 2; i++) chk(a);
  for (int i = n / 2 + 1; i <= n; i++) chk(b);
  if (a ^ b) return puts("NO"), 0;
  puts("YES");
}
