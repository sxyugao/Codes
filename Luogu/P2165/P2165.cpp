#include <cstdio>
#include <iostream>
using namespace std;
int n, x, ans, sum[30];
bool chk(int a, int b, int c, int d) {
  return sum[b] - sum[a] == sum[d] - sum[c] &&
         sum[c] - sum[b] == sum[n] - sum[d] + sum[a];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    sum[i] = sum[i - 1] + x;
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = j + 1; k <= n; k++)
        for (int l = k + 1; l <= n; l++) ans += chk(i, j, k, l);
  printf("%d", ans);
}
