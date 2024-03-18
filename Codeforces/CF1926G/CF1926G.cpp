#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n, f[N][2];
vector<int> v[N];
string s;
void init() {
  for (int i = 1; i <= n; ++i) {
    v[i].clear();
    f[i][0] = f[i][1] = 1e6;
  }
}
void dfs(int x, int fa) {
  int P = 0, S = 0;
  for (int y : v[x]) {
    if (y == fa) continue;
    dfs(y, x);
    P += min(f[y][0], f[y][1] + 1);
    S += min(f[y][1], f[y][0] + 1);
  }
  if (s[x - 1] == 'P') {
    f[x][0] = P;
  }
  if (s[x - 1] == 'S') {
    f[x][1] = S;
  }
  if (s[x - 1] == 'C') {
    f[x][0] = P;
    f[x][1] = S;
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    cin >> n;
    init();
    for (int x = 2; x <= n; ++x) {
      int y;
      cin >> y;
      v[x].emplace_back(y);
      v[y].emplace_back(x);
    }
    cin >> s;
    dfs(1, 0);
    cout << min(f[1][0], f[1][1]) << endl;
  }
}