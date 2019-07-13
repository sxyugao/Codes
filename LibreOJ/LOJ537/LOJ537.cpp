#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MX = 1050000;
const int N = 5e6 + 5;
int cnt[MX];
char s[N];
int n, k, ans;
int main() {
  gets(s + 1);
  scanf("%d", &k);
  n = strlen(s + 1);
  for (int i = 1; i <= n - k + 1; i++) {
    int tmp = 0;
    for (int j = i; j <= i + k - 1; j++) {
      int x;
      if (s[j] == 'A') x = 0;
      if (s[j] == 'G') x = 1;
      if (s[j] == 'C') x = 2;
      if (s[j] == 'T') x = 3;
      tmp = tmp * 4 + x;
    }
    cnt[tmp]++;
    ans = max(ans, cnt[tmp]);
  }
  printf("%d", ans);
}
