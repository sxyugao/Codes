#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
int l, r, a[15];
LL pw[15], ans[10];
LL dfs(int len, bool lim) {
  if (!len) return 1;
  if (!lim) return pw[len];
  return a[len] * dfs(len - 1, 0) + dfs(len - 1, 1);
}
inline LL calc(int x, int num) {
  int t = x;
  int len = 0;
  do {
    a[++len] = t % 10;
    t /= 10;
  } while (t);
  LL ans = 0;
  for (int i = 0; i < len - 1; i++) ans += pw[i];
  if (a[len] > num) ans += pw[len - 1];
  if (a[len] == num) ans += dfs(len - 1, 1);
  return ans;
}
int main() {
  scanf("%d%d", &l, &r);
  pw[0] = 1;
  for (int i = 1; i < 15; i++) pw[i] = pw[i - 1] * 10;
  for (int i = 2; i * i <= r; i++) {
    int x = max(i, l / i + (l % i != 0));
    int y = r / i;
    if (x > y) continue;
    int t = i;
    while (t > 9) t /= 10;
    ans[t] += y - x + 1;
    for (int j = 1; j <= 9; j++) ans[j] += calc(y, j) - calc(x, j);
    if (l <= i * i) ans[t]--;
    t = x;
    while (t > 9) t /= 10;
    ans[t]++;
  }
  ans[1] += r - l + 1;
  for (int i = 1; i <= 9; i++) ans[i] += calc(r, i) - calc(l, i);
  int t = l;
  while (t > 9) t /= 10;
  ans[t]++;
  if (l == 1) ans[1]--;
  for (int i = 1; i <= 9; i++) printf("%lld\n", ans[i]);
}
