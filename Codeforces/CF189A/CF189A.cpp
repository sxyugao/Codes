#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int f[4005];
int main() {
  int n, a, b, c;
  scanf("%d%d%d%d", &n, &a, &b, &c);
  memset(f, -1, sizeof(f));
  f[0] = 0;
  for (int i = a; i <= n; i++)
    if (~f[i - a]) f[i] = max(f[i], f[i - a] + 1);
  for (int i = b; i <= n; i++)
    if (~f[i - b]) f[i] = max(f[i], f[i - b] + 1);
  for (int i = c; i <= n; i++)
    if (~f[i - c]) f[i] = max(f[i], f[i - c] + 1);
  printf("%d", f[n]);
}