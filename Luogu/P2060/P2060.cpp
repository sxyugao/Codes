#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int dx[] = {1, 1, -1, -1, 2, 2, -2, -2};
const int dy[] = {2, -2, 2, -2, 1, -1, 1, -1};
struct Data {
  int x, y, step;
};
bool vis[200][200];
queue<Data> q;
int main() {
  int sx, sy, ex, ey, ans = 0;
  scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
  if (sx > ex) swap(sx, ex);
  if (sy > ey) swap(sy, ey);
  while (ey - sy >= 50 || ex - sx >= 50) {
    ans++, sx++, sy++;
    if (ey - sy > ex - sx) {
      sy++;
    } else {
      sx++;
    }
    if (sx > ex) swap(sx, ex);
    if (sy > ey) swap(sy, ey);
  }
  ex = ex - sx + 55;
  ey = ey - sy + 55;
  sx = sy = 55;
  q.push(Data{55, 55, 0});
  vis[55][55] = 1;
  while (!q.empty()) {
    Data now = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int tx = now.x + dx[i], ty = now.y + dy[i];
      if (tx < 0 || ty < 0 || tx > 150 || ty > 150) continue;
      if (vis[tx][ty]) continue;
      vis[tx][ty] = 1;
      q.push(Data{tx, ty, now.step + 1});
      if (tx == ex && ty == ey) {
        printf("%d", ans + now.step + 1);
        return 0;
      }
    }
  }
}