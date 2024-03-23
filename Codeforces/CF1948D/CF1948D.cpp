#include <iostream>
using namespace std;
const int N = 5005;
int f[N][N];
void solve() {
  string s;
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) f[i][j] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j)
      f[i][j - i] = s[i] == s[j] || s[i] == '?' || s[j] == '?';
  for (int ans = n / 2; ~ans; --ans) {
    for (int i = 0; i < n - ans; ++i) {
      if (f[i][ans] >= ans) {
        cout << ans * 2 << endl;
        return;
      }
      if (f[i + 1][ans]) {
        f[i + 1][ans] += f[i][ans];
      }
    }
  }
}
int main() {
  int T;
  cin >> T;
  while (T--) solve();
}