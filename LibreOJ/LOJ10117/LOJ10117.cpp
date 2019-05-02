#include <cstdio>
#include <iostream>
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
int lowbit(int x) { return x & -x; }
int n, m, opt, l, r;
bool tree[N];
void modify(int x) {
  for (; x <= n; x += lowbit(x)) tree[x] ^= 1;
}
bool query(int x) {
  bool ans = 0;
  for (; x; x -= lowbit(x)) ans ^= tree[x];
  return ans;
}
int main() {
  n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    opt = read();
    if (opt == 1) {
      l = read(), r = read();
      modify(l), modify(r + 1);
    } else {
      printf("%d\n", query(read()));
    }
  }
}