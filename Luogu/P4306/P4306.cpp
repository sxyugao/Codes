#include <bitset>
#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2005;
int n;
char s[N];
bitset<N> f[N];
int main() {
  scanf("%d\n", &n);
  for (int i = 1; i <= n; i++) {
    gets(s + 1);
    f[i].set(i);
    for (int j = 1; j <= n; j++)
      if (s[j] ^ '0') f[i].set(j);
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (f[j][i]) f[j] |= f[i];
  int ans = 0;
  for (int i = 1; i <= n; i++) ans += f[i].count();
  printf("%d", ans);
}
