#include <stdio.h>
#define P 998244353
#define N 200005
int T, fac[N];
char s[N];
int main() {
  fac[0] = 1;
  for (int i = 1; i < N - 5; ++i) fac[i] = 1LL * fac[i - 1] * i % P;
  scanf("%d\n", &T);
  while (T--) {
    gets(s);
    int cnt = 1;
    int tot = 0, ans = 1;
    for (int i = 1; s[i]; ++i) {
      if (s[i] == s[i - 1]) {
        ++cnt;
        continue;
      }
      tot += cnt - 1;
      ans = 1LL * ans * cnt % P;
      cnt = 1;
    }
    tot += cnt - 1;
    ans = 1LL * ans * cnt % P;
    printf("%d %d\n", tot, 1LL * ans * fac[tot] % P);
  }
}