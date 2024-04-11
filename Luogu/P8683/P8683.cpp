#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1e5 + 5;
int n, m, a[N];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n >> m;
  vector<int> a(n + m + 1);
  for (int i = 0; i < n + m + 1; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  long long ans = 0;
  if (m) {
    ans = *a.rbegin() - *a.begin();
    for (int i = 1; i < n + m; ++i) ans += abs(a[i]);
  } else {
    for (int x : a) ans += x;
  }
  cout << ans << endl;
}