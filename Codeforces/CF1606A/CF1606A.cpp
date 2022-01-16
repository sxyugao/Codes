#include <cstdio>
#include <cstring>
char s[1005];
int main() {
  int T;
  scanf("%d\n", &T);
  while (T--) {
    gets(s);
    int len = strlen(s) - 1;
    if (s[0] != s[len]) s[len] = s[0];
    puts(s);
  }
}