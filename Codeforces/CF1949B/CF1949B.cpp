#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int main() {
  int T, n;
  cin >> T;
  while (T--) {
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      int tmp = 2e9;
      for (int j = 0; j < n; ++j) {
        tmp = min(tmp, abs(a[j] - b[(i + j) % n]));
      }
      ans = max(ans, tmp);
    }
    cout << ans << endl;
  }
}