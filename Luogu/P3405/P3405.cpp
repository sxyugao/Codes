#include <cstdio>
#include <iostream>
using namespace std;
int n, ans, cnt[1005][1005];
char a[15], b[15];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s%s", a, b);
    int A = (a[0] - 'A') * 26 + a[1];
    int B = (b[0] - 'A') * 26 + b[1];
    ans += cnt[B][A];
    if (A == B) ans -= cnt[A][B];
    cnt[A][B]++;
  }
  printf("%d", ans);
}