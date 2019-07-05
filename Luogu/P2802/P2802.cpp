#include <cstdio>
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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
struct Data {
  int x, y, hp, step;
};
queue<Data> q;
int a[10][10];
bool vis[10][10][10];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      a[i][j] = read();
      if (a[i][j] == 2) {
        q.push(Data{i, j, 5, 0});
        vis[i][j][5] = 1;
      }
    }
  while (!q.empty()) {
    Data now = q.front();
    q.pop();
    if (!now.hp) continue;
    for (int i = 0; i < 4; i++) {
      int tx = now.x + dx[i], ty = now.y + dy[i];
      if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
      if (!a[tx][ty]) continue;
      if (a[tx][ty] == 3) return printf("%d", now.step + 1), 0;
      if (a[tx][ty] != 4) {
        if (vis[tx][ty][now.hp - 1]) continue;
        vis[tx][ty][now.hp - 1] = 1;
        q.push(Data{tx, ty, now.hp - 1, now.step + 1});
      } else {
        if (vis[tx][ty][5]) continue;
        vis[tx][ty][5] = 1;
        q.push(Data{tx, ty, 5, now.step + 1});
      }
    }
  }
  puts("-1");
}