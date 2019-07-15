#include <cstdio>
#include <iostream>
using namespace std;
int a[1024][1024];
void dfs(int x, int y, int l) {
  if (l == 2) return (void)(a[x + 1][y] = a[x][y + 1] = a[x + 1][y + 1] = 1);
  int nxt = l / 2;
  int midx = x + nxt, midy = y + nxt;
  dfs(midx, y, nxt);
  dfs(x, midy, nxt);
  dfs(midx, midy, nxt);
}
int main() {
  int n;
  scanf("%d", &n);
  n = (1 << n);
  dfs(0, 0, n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) printf("%d ", a[i][j]);
    puts("");
  }
}
