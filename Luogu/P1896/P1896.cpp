#include <cstdio>
int n, m, num, st[150], cnt[150];
long long f[10][150][85];
void init(int k, int tot, int pos) {
  if (pos > n) {
    st[++num] = k;
    cnt[num] = tot;
    return;
  }
  init(k, tot, pos + 1);
  init(k | (1 << (pos - 1)), tot + 1, pos + 2);
}
int main() {
  scanf("%d%d", &n, &m);
  init(0, 0, 1);
  for (int i = 1; i <= num; i++) f[1][i][cnt[i]] = 1;
  for (int i = 2; i <= n; i++)
    for (int j = 1; j <= num; j++)
      for (int k = 1; k <= num; k++) {
        if (st[j] & st[k]) continue;
        if ((st[j] << 1) & st[k]) continue;
        if (st[j] & (st[k] << 1)) continue;
        for (int p = m; p >= cnt[j]; p--) f[i][j][p] += f[i - 1][k][p - cnt[j]];
      }
  for (int i = 1; i < num; i++) f[n][num][m] += f[n][i][m];
  printf("%lld", f[n][num][m]);
}