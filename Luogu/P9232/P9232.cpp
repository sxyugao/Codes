#include <iostream>
using namespace std;
const int N = 5005;
bool f[N][N];
int main() {
  string s;
  cin >> s;
  for (unsigned i = 1; i < s.size(); ++i) {
    f[i - 1][i] = s[i - 1] > s[i];
  }
  for (unsigned len = 3; len <= s.size(); ++len)
    for (int l = 0; l + len <= s.size(); ++l) {
      int r = l + len - 1;
      if (s[l] > s[r]) f[l][r] = 1;
      if (s[l] == s[r]) f[l][r] = f[l + 1][r - 1];
    }
  int ans = 0;
  for (int l = 0; l < s.size(); ++l)
    for (int r = l; r < s.size(); ++r) ans += f[l][r];
  cout << ans << endl;
}