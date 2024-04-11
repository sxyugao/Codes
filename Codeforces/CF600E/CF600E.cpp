#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n, mx, c[N], cnt[N], son[N], siz[N];
long long ans[N], cnt_sum[N];
vector<int> g[N];
void dfs(int x, int f) {
  siz[x] = 1;
  for (auto y : g[x]) {
    if (y == f) continue;
    dfs(y, x);
    siz[x] += siz[y];
    if (siz[son[x]] < siz[y]) son[x] = y;
  }
}
void add(int x, int f) {
  if (cnt[c[x]]) cnt_sum[cnt[c[x]]] -= c[x];
  cnt_sum[++cnt[c[x]]] += c[x];
  if (cnt[c[x]] > mx) mx = cnt[c[x]];
  for (auto y : g[x]) {
    if (y == f) continue;
    add(y, x);
  }
}
void del(int x, int f) {
  cnt_sum[cnt[c[x]]] -= c[x];
  --cnt[c[x]];
  if (cnt[c[x]] > 0) cnt_sum[cnt[c[x]]] += c[x];
  mx -= !cnt_sum[mx];
  for (auto y : g[x]) {
    if (y == f) continue;
    del(y, x);
  }
}
void calc(int x, int f, bool keep) {
  for (auto y : g[x]) {
    if (y == f || y == son[x]) continue;
    calc(y, x, false);
  }
  if (son[x]) calc(son[x], x, true);
  if (cnt[c[x]]) cnt_sum[cnt[c[x]]] -= c[x];
  cnt_sum[++cnt[c[x]]] += c[x];
  if (cnt[c[x]] > mx) mx = cnt[c[x]];
  for (auto y : g[x]) {
    if (y == f || y == son[x]) continue;
    add(y, x);
  }
  ans[x] = cnt_sum[mx];
  if (!keep) del(x, f);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> c[i];
  for (int i = 1; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  dfs(1, 0);
  calc(1, 0, true);
  for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
}
