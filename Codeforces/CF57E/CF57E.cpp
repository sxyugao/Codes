#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
typedef long long LL;
#define gc c = getchar()
LL read() {
  LL x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int dx[] = {2, 2, 1, 1, -2, -2, -1, -1};
const int dy[] = {1, -1, 2, -2, 1, -1, 2, -2};
bool vis[5000][5000];
struct Point {
  Point(){};
  Point(int X, int Y, int T) { x = X, y = Y, t = T; }
  int x, y, t;
};
queue<Point> q;
int n;
LL k, ans[505];
const LL P = 1000000007;
int main() {
  k = read(), n = read();
  for (int i = 1; i <= n; i++) {
    int x = read(), y = read();
    vis[x + 2000][y + 2000] = 1;
  }
  q.push(Point(2000, 2000, 0));
  ans[0] = 1;
  vis[2000][2000] = 1;
  while (!q.empty() && q.front().t < min(k, (LL)500)) {
    Point now = q.front();
    q.pop();
    for (int i = 0; i < 8; i++) {
      int tx = now.x + dx[i], ty = now.y + dy[i];
      if (!vis[tx][ty]) {
        ans[now.t + 1]++;
        vis[tx][ty] = 1;
        q.push(Point(tx, ty, now.t + 1));
      }
    }
  }
  LL Ans = 0;
  if (k <= 500)
    for (int i = 0; i <= k; i++) Ans += ans[i];
  else {
    LL d = ans[500] - ans[499];
    for (int i = 0; i < 500; i++) Ans += ans[i];
    k -= 499;
    k %= P;
    Ans = (Ans + ans[500] * k + (k - 1) * k / 2 % P * d) % P;
  }
  printf("%lld", Ans);
}
