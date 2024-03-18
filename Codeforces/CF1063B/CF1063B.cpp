#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
const int N = 2005;
struct Data {
  int x, y, l, r;
};
int n, m, r, c, lim_x, lim_y, ans;
deque<Data> q;
bool vis[N][N];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {-1, 1, 0, 0};
char mp[N][N];
int main() {
  scanf("%d%d%d%d%d%d\n", &n, &m, &r, &c, &lim_x, &lim_y);
  for (int i = 1; i <= n; ++i) fgets(mp[i] + 1, m + 2, stdin);
  q.push_back(Data{r, c, lim_x, lim_y});
  while (!q.empty()) {
    Data node = q.front();
    q.pop_front();
    if (vis[node.x][node.y]) continue;
    vis[node.x][node.y] = 1;
    ++ans;
    for (int i = 0; i < 4; ++i) {
      int tx = node.x + dx[i];
      int ty = node.y + dy[i];
      if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
      if (vis[tx][ty] || mp[tx][ty] == '*') continue;
      switch (i) {
        case 0:
          if (node.l) q.push_back(Data{tx, ty, node.l - 1, node.r});
          break;
        case 1:
          if (node.r) q.push_back(Data{tx, ty, node.l, node.r - 1});
          break;
        default:
          q.push_front(Data{tx, ty, node.l, node.r});
          break;
      }
    }
  }
  printf("%d", ans);
}
