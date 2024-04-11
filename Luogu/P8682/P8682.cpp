#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int d = a[1] - a[0];
  if (d == 0) return cout << n << endl, 0;
  for (int i = 2; i < n; ++i) d = gcd(d, a[i] - a[i - 1]);
  int ans = n;
  for (int i = 1; i < n; ++i) ans += (a[i] - a[i - 1]) / d - 1;
  cout << ans << endl;
}
