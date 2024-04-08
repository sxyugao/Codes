#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Array;
typedef vector<vector<int>> Edge;
Edge e;
Array c, siz, son, cnt(200005), ccnt;
int n, ans;
void dfs(int x) {
  siz[x] = 1;
  for (auto y : e[x]) {
    dfs(y);
    siz[x] += siz[y];
    if (siz[y] > siz[son[x]]) son[x] = y;
  }
}
void add(int x) {
  --ccnt[cnt[c[x]]];
  ++ccnt[++cnt[c[x]]];
  for (auto y : e[x]) add(y);
}
void del(int x) {
  --ccnt[cnt[c[x]]];
  ++ccnt[--cnt[c[x]]];
  for (auto y : e[x]) del(y);
}
void calc(int x, bool keep) {
  for (auto y : e[x])
    if (y != son[x]) calc(y, false);
  if (son[x]) calc(son[x], true);
  --ccnt[cnt[c[x]]];
  ++ccnt[++cnt[c[x]]];
  for (auto y : e[x])
    if (y != son[x]) add(y);
  ans += cnt[c[x]] * ccnt[cnt[c[x]]] == siz[x];
  if (!keep) del(x);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  e = Edge(n + 1);
  c = Array(n + 1);
  siz = Array(n + 1);
  son = Array(n + 1);
  ccnt = Array(n + 1);
  for (int i = 1; i <= n; ++i) {
    int j;
    cin >> c[i];
    cin >> j;
    if (j) e[j].push_back(i);
  }
  dfs(1);
  calc(1, true);
  cout << ans << endl;
}