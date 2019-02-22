#include <stdio.h>
#include <string.h>
#define N 1000000
char s[N + 5];
int nxt[N + 5];
int main() {
  while (~scanf("%s", s + 1)) {
    if (s[1] == '.') break;
    int len = strlen(s + 1), i, j = nxt[0] = 0;
    for (i = 2; i <= len; i++) {
      while (j && s[i] != s[j + 1]) j = nxt[j];
      if (s[j + 1] == s[i]) j++;
      nxt[i] = j;
    }
    if (!nxt[len] || len % (len - nxt[len])) {
      puts("1");
    } else {
      printf("%d\n", len / (len - nxt[len]));
    }
  }
}
