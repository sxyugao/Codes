#include <cstdio>
#include <iostream>
using namespace std;
const int n = 4;
int a[5][5];
bool vis[20];
void dfs(int x, int y) {
  if (x > n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i][i];
    if (sum != 34) return;
    sum = 0;
    sum += a[1][1];
    sum += a[1][n];
    sum += a[n][1];
    sum += a[n][n];
    if (sum != 34) return;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) printf("%d ", a[i][j]);
      puts("");
    }
    puts("");
  }
  if ((x % 2 == 0 && y % 2 && y > 1) || (x == n - 1 && y == n)) {
    int sum = 0;
    sum += a[x - 1][y - 2];
    sum += a[x - 1][y - 1];
    sum += a[x][y - 2];
    sum += a[x][y - 1];
    if (sum != 34) return;
  }
  if (x == n && y == 2) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i][n - i + 1];
    if (sum != 34) return;
  }
  if (x == n && y > 1) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[i][y - 1];
    if (sum != 34) return;
  }
  if (y > n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) sum += a[x][i];
    if (sum != 34) return;
    return dfs(x + 1, 1);
  }
  if (a[x][y]) return dfs(x, y + 1);
  for (int i = 1; i <= n * n; i++)
    if (!vis[i]) {
      a[x][y] = i;
      vis[i] = 1;
      dfs(x, y + 1);
      vis[i] = 0;
      a[x][y] = 0;
    }
}
int main() {
  int x, y;
  scanf("%d%d", &x, &y);
  a[x][y] = vis[1] = 1;
  dfs(1, 1);
}