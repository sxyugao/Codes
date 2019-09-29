#include <cstdio>
#include <iostream>
using namespace std;
const int N = 2e5 + 5;
int n, p[26], e[26][26];
char a[N], b[N];
int main() {
  scanf("%d\n", &n);
  gets(a + 1), gets(b + 1);
  int ans = 0;
  for (int i = 1; i <= n; i++)
    if (a[i] ^ b[i]) {
      ans++;
      p[b[i] - 'a'] = i;
      e[a[i] - 'a'][b[i] - 'a'] = i;
    }
  for (int i = 0; i < 26; i++)
    for (int j = 0; j < 26; j++)
      if (e[i][j] && e[j][i])
        return printf("%d\n%d %d", ans - 2, e[i][j], e[j][i]), 0;
  for (int i = 1; i <= n; i++)
    if (a[i] ^ b[i] && p[a[i] - 'a'])
      return printf("%d\n%d %d", ans - 1, i, p[a[i] - 'a']), 0;
  printf("%d\n", ans);
  puts("-1 -1");
}
