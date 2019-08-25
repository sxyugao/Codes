#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
int n, m, f[200][200];
map<string, int> id;
string a, b;
bool e[200][200];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL), cout.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a;
    id[a] = i;
  }
  for (int i = 1; i <= m; i++) {
    cin >> a >> b;
    e[id[a]][id[b]] = e[id[b]][id[a]] = 1;
  }
  f[1][1] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      for (int k = 1; k < j; k++)
        if (e[k][j] && f[i][k]) f[i][j] = f[j][i] = max(f[i][j], f[i][k] + 1);
  int ans = 1;
  for (int i = 1; i <= n; i++)
    if (e[i][n]) ans = max(ans, f[i][n]);
  cout << ans << endl;
}