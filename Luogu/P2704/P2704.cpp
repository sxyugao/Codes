#include <cstdio>
#include <iostream>
using namespace std;
const int N = 105;
const int M = 10;
int n, m, tot, s[1 << M], cnt[1 << M];
char str[M];
int a[N], f[2][1 << M][1 << M];
void init(int k, int t, int num) {
  if (k > m) return (void)(s[++tot] = t, cnt[tot] = num);
  init(k + 1, t << 1, num);
  if (t & 1 || (t >> 1) & 1) return;
  init(k + 1, t << 1 | 1, num + 1);
}
int main() {
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n; i++) {
    gets(str + 1);
    for (int j = 1; j <= m; j++) a[i] = a[i] << 1 | (str[j] == 'H');
  }
  init(1, 0, 0);
  for (int i = 1; i <= tot; i++)
    if (!(s[i] & a[1])) f[1][i][1] = cnt[i];
  for (int i = 1; i <= tot && n > 1; i++) {
    if (s[i] & a[2]) continue;
    for (int j = 1; j <= tot; j++) {
      if (s[i] & s[j]) continue;
      if (s[j] & a[1]) continue;
      f[0][i][j] = max(f[0][i][j], f[1][j][1] + cnt[i]);
    }
  }
  for (int i = 3; i <= n; i++) {
    int now = i & 1, lst = now ^ 1;
    for (int j = 1; j <= tot; j++) {
      if (s[j] & a[i]) continue;
      for (int k = 1; k <= tot; k++) {
        if (s[k] & a[i - 1]) continue;
        if (s[j] & s[k]) continue;
        for (int l = 1; l <= tot; l++) {
          if (s[l] & a[i - 2]) continue;
          if (s[l] & s[k]) continue;
          if (s[l] & s[j]) continue;
          f[now][j][k] = max(f[now][j][k], f[lst][k][l] + cnt[j]);
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= tot; i++)
    for (int j = 1; j <= tot; j++)
      ans = max(ans, f[n & 1][i][j]);
  printf("%d", ans);
}
