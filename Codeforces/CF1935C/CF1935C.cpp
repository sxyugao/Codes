#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const int N = 2000;
struct Data {
  int a, b;
} a[N];
int main() {
  for (int T = read(); T; --T) {
    int n = read(), lim = read();
    for (int i = 0; i < n; ++i) {
      a[i].a = read();
      a[i].b = read();
    }
    sort(a, a + n, [&](const Data &a, const Data &b) { return a.b < b.b; });
    size_t ans = 0;
    for (int l = 0; l < n; ++l) {
      priority_queue<int> q;
      int sum = 0;
      for (int r = l; r < n; ++r) {
        q.push(a[r].a);
        sum += a[r].a;
        while (!q.empty() && sum + a[r].b - a[l].b > lim) {
          sum -= q.top();
          q.pop();
        }
        ans = max(ans, q.size());
      }
    }
    cout << ans << endl;
  }
}
