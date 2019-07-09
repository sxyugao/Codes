#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
const int N = 1e5 + 5;
multiset<int> s;
vector<int> v;
int a[N];
int main() {
  int n = read(), k = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  int l = 1, r = 1, ans = 1, now = 1;
  s.insert(a[1]), v.push_back(1);
  while (r < n) {
    s.insert(a[++r]);
    now++;
    while (*s.rbegin() - *s.begin() > k) s.erase(s.find(a[l++])), now--;
    if (now > ans) {
      ans = now;
      v.clear();
      v.push_back(l);
    } else if (now == ans) {
      v.push_back(l);
    }
  }
  printf("%d %d\n", ans, (int)v.size());
  for (int x : v) printf("%d %d\n", x, x + ans - 1);
}
