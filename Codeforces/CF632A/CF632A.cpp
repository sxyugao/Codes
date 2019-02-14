#include <cstdio>
#include <iostream>
using namespace std;
int n, p, cnt;
long long ans;
void solve(int x) {
  if (!x) return;
  string s;
  cin >> s;
  solve(x - 1);
  ans <<= 1;
  if (s == "halfplus") {
    cnt++;
    ans++;
  }
}
int main() {
  cin >> n >> p;
  solve(n);
  printf("%lld", ans * p - p / 2 * cnt);
}