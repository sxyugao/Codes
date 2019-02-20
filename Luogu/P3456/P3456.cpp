#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1005;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int a[N][N];
bool vis[N][N];
struct Data {
  int x, y;
};
queue<Data> q;
int mx, mn, ans1, ans2;
void bfs(int x, int y) {
  while (!q.empty()) q.pop();
  q.push(Data{x, y});
  vis[x][y] = 1;
  mx = -1e9, mn = 1e9;
  while (!q.empty()) {
    Data now = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int tx = now.x + dx[i], ty = now.y + dy[i];
      if (a[tx][ty] != a[now.x][now.y]) {
        if (~a[tx][ty]) {
          mx = max(mx, a[tx][ty]);
          mn = min(mn, a[tx][ty]);
        }
        continue;
      }
      if (vis[tx][ty]) continue;
      vis[tx][ty] = 1;
      q.push(Data{tx, ty});
    }
  }
}
int main() {
  int n = read();
  memset(a, -1, sizeof(a));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) a[i][j] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (vis[i][j]) continue;
      bfs(i, j);
      if (mx <= a[i][j]) ans1++;
      if (mn >= a[i][j]) ans2++;
    }
  printf("%d %d", ans1, ans2);
}