#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
const int N = 5e5 + 5;
struct Heap {
  int siz, a[N];
  void push(int x) {
    a[++siz] = x;
    push_heap(a + 1, a + siz + 1, greater<int>());
  }
  int pop() {
    pop_heap(a + 1, a + siz + 1, greater<int>());
    return a[siz--];
  }
  int top() { return a[1]; }
} h;
int tot, a[N], b[N], cnt[N];
int main() {
  int n = read();
  long long ans = 0;
  for (int i = 1; i <= n; i++) ans += a[i] = read();
  sort(a + 1, a + n + 1, greater<int>());
  for (int i = 1, j; i <= n; i = j) {
    j = i;
    a[++tot] = a[i];
    while (a[i] == a[j]) j++, cnt[tot]++;
  }
  int sum = 0;
  for (int i = 1; i <= tot; i++) {
    int x = a[i];
    int num = min(sum - h.siz * 2, cnt[i]);
    sum += cnt[i];
    while (num) b[++b[0]] = x, num--, cnt[i]--;
    while (cnt[i] > 1 && h.siz) {
      int y = h.top();
      if (y >= x * 2) break;
      cnt[i] -= 2;
      h.pop();
      if (y > x) {
        b[++b[0]] = y;
        b[++b[0]] = 2 * x - y;
      } else {
        b[++b[0]] = x;
        b[++b[0]] = x;
      }
    }
    if (cnt[i] && h.siz && h.top() < x) h.pop(), b[++b[0]] = x;
    while (b[0]) h.push(b[b[0]--]);
  }
  while (h.siz) ans -= h.pop();
  printf("%lld", ans);
}
