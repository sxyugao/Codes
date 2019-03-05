#include <algorithm>
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
const int N = 2e5 + 5;
struct Data {
  int id, x;
  bool operator<(const Data &b) const {
    if (x != b.x) return x < b.x;
    return id < b.id;
  }
} a[N];
int n, tree[N], ans[N];
int lowbit(int x) { return x & -x; }
int sum(int x) {
  int ans = 0;
  for (; x > 0; x -= lowbit(x)) ans += tree[x];
  return ans;
}
void add(int x) {
  for (; x <= n; x += lowbit(x)) tree[x]++;
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i].x = read(), a[i].id = i;
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < n && (a[i].id - 1) * j + 1 < n; j++)
      ans[j] += sum(min(a[i].id * j + 1, n)) - sum((a[i].id - 1) * j + 1);
    add(a[i].id);
  }
  for (int i = 1; i < n; i++) printf("%d ", ans[i]);
}