#include <algorithm>
#include <cstdio>
int n, a[105], ans[105];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", a + i);
  std::sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++)
    if (i % 2 == 0) printf("%d ", a[i]);
  for (int i = n; i; i--)
    if (i & 1) printf("%d ", a[i]);
}