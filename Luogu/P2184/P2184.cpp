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
int n, m;
int lowbit(int x) {
  return x & -x;
}
struct Tree {
  int tree[N];
  void add(int x) {
    for (; x <= n; x += lowbit(x)) tree[x]++;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += tree[x];
    return ans;
  }
} t1, t2;
int main() {
  n = read(), m = read();
  while (m--) {
    int opt = read(), l = read(), r = read();
    if (opt == 1) {
      t1.add(l), t2.add(r);
    } else {
      printf("%d\n", t1.query(r) - t2.query(l - 1));
    }
  }
}