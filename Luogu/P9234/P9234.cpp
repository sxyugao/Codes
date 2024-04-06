#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
int n, ans;
long long m, a[40];
unordered_map<long long, int> f;
void dfs1(int x, long long tot, int cnt) {
  if (tot > m) return;
  if (x > n / 2) {
    if (f.find(tot) == f.end() || f[tot] > cnt) f[tot] = cnt;
    return;
  }
  dfs1(x + 1, tot, cnt);
  dfs1(x + 1, tot + a[x], cnt + 1);
  dfs1(x + 1, tot + a[x] * 2, cnt);
}
void dfs2(int x, long long tot, int cnt) {
  if (cnt >= ans) return;
  if (tot > m) return;
  if (x > n) {
    if (f.find(m - tot) != f.end() && f[m - tot] + cnt < ans) {
      ans = f[m - tot] + cnt;
    }
    return;
  }
  dfs2(x + 1, tot, cnt);
  dfs2(x + 1, tot + a[x], cnt + 1);
  dfs2(x + 1, tot + a[x] * 2, cnt);
}
int main() {
  cin >> n >> m;
  m <<= 1;
  ans = n + 1;
  long long tot = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    tot += a[i] << 1;
  }
  if (tot < m) {
    cout << -1 << endl;
    return 0;
  }
  sort(a + 1, a + n + 1);
  dfs1(1, 0, 0);
  dfs2(n / 2 + 1, 0, 0);
  cout << ((ans == n + 1) ? -1 : ans) << endl;
}