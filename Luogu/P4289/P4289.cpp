#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int n = 4;
const int m = 4;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
queue<int> q;
char c;
int S, T, x;
int vis[200000];
bool a[5][5];
void input() {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      c = getchar();
      while (isspace(c)) c = getchar();
      a[i][j] = c ^ '0';
    }
}
int get() {
  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) ans = (ans << 1) | a[i][j];
  return ans;
}
void restore(int x) {
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) a[i][j] = x & (1 << ((n - i + 1) * m - j));
}
int main() {
  input(), S = get();
  input(), T = get();
  memset(vis, 0x3f, sizeof(vis));
  q.push(S);
  vis[S] = 0;
  while (!q.empty()) {
    x = q.front(), q.pop();
    restore(x);
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++)
        for (int k = 0; k < 4 && a[i][j]; k++) {
          int tx = i + dx[k], ty = j + dy[k];
          if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
          if (a[tx][ty]) continue;
          a[i][j] = 0, a[tx][ty] = 1;
          int y = get();
          if (vis[y] > 1e9) {
            q.push(y);
            vis[y] = vis[x] + 1;
          }
          a[i][j] = 1, a[tx][ty] = 0;
        }
  }
  printf("%d", vis[T]);
}
