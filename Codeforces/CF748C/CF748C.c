#include <stdbool.h>
#include <stdio.h>
#include <string.h>
int n, ans;
char s[200000];
bool vis[4];
int main() {
  scanf("%d\n", &n);
  gets(s);
  for (int i = 0; i < n; i++) {
    int p = 0;
    if (s[i] == 'L') p = 0;
    if (s[i] == 'R') p = 1;
    if (s[i] == 'U') p = 2;
    if (s[i] == 'D') p = 3;
    if (vis[p ^ 1]) {
      ans++;
      memset(vis, 0, sizeof(0));
    }
    vis[p] = 1;
  }
  printf("%d", ans + 1);
}