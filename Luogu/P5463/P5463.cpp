#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef __int128 BigInt;
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
#define pc putchar
void write(BigInt x) {
  if (x < 0) x = -x, pc('-');
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
#undef pc
const int N = 1e6 + 5;
int num, a[N], b[N];
BigInt tree[N];
int lowbit(int x) { return x & -x; }
void add(int x, int y) {
  for (; x <= num; x += lowbit(x)) tree[x] += y;
}
BigInt query(int x) {
  BigInt ans = 0;
  for (; x; x -= lowbit(x)) ans += tree[x];
  return ans;
}
BigInt ans;
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) a[i] = b[i] = read();
  sort(b + 1, b + n + 1);
  num = unique(b + 1, b + n + 1) - b - 1;
  for (int i = n; i; i--) {
    int id = lower_bound(b + 1, b + num + 1, a[i]) - b;
    ans += query(id - 1) * i;
    add(id, n - i + 1);
  }
  write(ans);
}
