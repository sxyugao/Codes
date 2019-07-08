#include <cstdio>
#include <iostream>
using namespace std;
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m, k, tot;
char s[505][505];
bool vis[505][505];
void dfs(int x, int y) {
  if (!tot) return;
  if (x < 1 || x > n || y < 1 || y > m) return;
  if (s[x][y] == '#') return;
  if (vis[x][y]) return;
  vis[x][y] = 1;
  tot--;
  for (int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i]);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  tot = -k;
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.') tot++;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.') {
        dfs(i, j);
        break;
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '.' && !vis[i][j]) s[i][j] = 'X';
  for (int i = 1; i <= n; i++) puts(s[i] + 1);
}