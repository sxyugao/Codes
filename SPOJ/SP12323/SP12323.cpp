#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
const int dx[8] = {1, -1, 2, -2, 1, -1, 2, -2};
const int dy[8] = {2, 2, 1, 1, -2, -2, -1, -1};
int T;
char a[5], b[5];
struct Data {
  Data(int _x, int _y) {
    x = _x, y = _y;
  }
  int x, y;
};
int vis[10][10];
int bfs(int sx, int sy, int ex, int ey) {
  if (sx == ex && sy == ey) return 0;
  memset(vis, 0, sizeof(vis));
  queue<Data> q;
  q.push(Data(sx, sy));
  vis[sx][sy] = 1;
  while (!q.empty()) {
    int x = q.front().x, y = q.front().y;
    q.pop();
    for (int i = 0; i < 8; i++) {
      int tx = x + dx[i], ty = y + dy[i];
      if (tx < 1 || tx > 8 || ty < 1 || ty > 8) continue;
      if (vis[tx][ty]) continue;
      if (tx == ex && ty == ey) return vis[x][y];
      vis[tx][ty] = vis[x][y] + 1;
      q.push(Data(tx, ty));
    }
  }
  return 0;
}
int main() {
  scanf("%d", &T);
  while (T--) {
    scanf("%s%s", a, b);
    int sx = a[0] - 'a' + 1, sy = a[1] - '0';
    int ex = b[0] - 'a' + 1, ey = b[1] - '0';
    printf("%d\n", bfs(sx, sy, ex, ey));
  }
}