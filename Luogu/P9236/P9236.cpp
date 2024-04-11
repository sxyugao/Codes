#include <iostream>
using namespace std;
const int N = 1e5;
int n, a[N];
long long ans;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i] ^= a[i - 1];
  }
  for (int j = 0; j <= 20; ++j) {
    long long cnt[2] = {1, 0};
    for (int i = 0; i < n; ++i) {
      bool t = (a[i] >> j) & 1;
      ans += cnt[!t] * (1 << j);
      ++cnt[t];
    }
  }
  cout << ans << endl;
}
