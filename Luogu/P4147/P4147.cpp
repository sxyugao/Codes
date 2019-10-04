#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1005;
int n, m, l[N][N], r[N][N], h[N][N];
bool a[N][N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      char c;
      cin >> c;
      if (c == 'F') a[i][j] = 1;
    }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (a[i][j]) l[i][j] = l[i][j - 1] + 1;
  for (int i = 1; i <= n; i++)
    for (int j = m; j; j--)
      if (a[i][j]) r[i][j] = r[i][j + 1] + 1;
  for (int i = 0; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!a[i][j]) l[i][j] = r[i][j] = 1e9;
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (a[i][j]) {
        h[i][j] = h[i - 1][j] + 1;
        l[i][j] = min(l[i - 1][j], l[i][j]);
        r[i][j] = min(r[i - 1][j], r[i][j]);
      }
      ans = max((r[i][j] + l[i][j] - 1) * h[i][j], ans);
    }
  printf("%d", ans * 3);
}