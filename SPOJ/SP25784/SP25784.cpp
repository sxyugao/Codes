#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x * f;
}
char obuf[1 << 14], *p = obuf;
inline void pc(char c) {
  if (obuf + (1 << 14) == p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    p = obuf;
  }
  *p++ = c;
}
inline void fsh() {
  fwrite(obuf, 1, p - obuf, stdout);
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 1e4 + 5;
const int P = 1e7 + 7;
void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
int a[N], b[N];
#define lowbit(x) (x & -x)
struct Tree {
  int n, tree[N];
  void init(int _n) {
    n = _n;
    memset(tree, 0, 4 * n);
  }
  void add(int x) {
    for (; x <= n; x += lowbit(x)) tree[x]++;
  }
  int query(int x) {
    int ans = 0;
    for (; x; x -= lowbit(x)) ans += tree[x];
    return ans;
  }
} Tr;
int main() {
  int T = read();
  for (int i = 1; i <= T; i++) {
    int n = read();
    for (int i = 1; i <= n; i++) a[i] = b[i] = read();
    sort(b + 1, b + n + 1);
    int num = unique(b + 1, b + n + 1) - b - 1;
    for (int i = 1; i <= n; i++) a[i] = lower_bound(b + 1, b + num + 1, a[i]) - b;
    Tr.init(n);
    int ans = 0;
    for (int i = n; i; i--) {
      Add(ans, Tr.query(a[i] - 1));
      Tr.add(a[i]);
    }
    pc('C'), pc('a'), pc('s'), pc('e'), pc(' ');
    write(i), pc(':'), pc(' '), write(ans), pc('\n');
  }
  fsh();
}
