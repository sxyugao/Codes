#include <stdio.h>
char s[100005];
int main() {
  gets(s);
  int ans = -1, tmp = 0;
  for (register int i = 0; s[i]; i++) {
    tmp += s[i] == '0' ? 1 : -1;
    if (tmp > ans) ans = tmp;
    if (tmp < 0) tmp = 0;
  }
  printf("%d", ans);
}
