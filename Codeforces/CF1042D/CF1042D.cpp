#include <bits/stdc++.h>
using namespace std;
#define int long long
#define lowbit(x) x & -x
#define N 200005
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
struct Data {
  int num, now, id;
  bool operator<(const Data& x) const {
    return num < x.num;
  }
} a[N];
int n, k, ans, w[N];
bool cmp(Data x, Data y) {
  return x.id < y.id;
}
int tree[N];
void add(int x, int num) {
  for (; x <= n; x += lowbit(x)) tree[x] += num;
}
int sum(int x) {
  int ans = 0;
  for (; x; x -= lowbit(x)) ans += tree[x];
  return ans;
}
int calc(int num) {
  int l = 0, r = n;
  while (l + 1 < r) {
    int mid = (l + r) >> 1;
    if (w[mid] >= num)
      r = mid;
    else
      l = mid;
  }
  if (w[r] < num) l = r;
  return sum(l);
}
signed main() {
  n = read(), k = read();
  for (int i = 1; i <= n; i++) {
    a[i].num = a[i - 1].num + read();
    a[i].id = i;
  }
  sort(a + 1, a + n + 1);
  a[1].now = 1;
  w[1] = a[1].num;
  add(a[1].now, 1);
  for (int i = 2; i <= n; i++) {
    if (a[i].num == a[i - 1].num) {
      a[i].now = a[i - 1].now;
    } else {
      a[i].now = i;
    }
    w[i] = a[i].num;
    add(a[i].now, 1);
  }
  sort(a + 1, a + n + 1, cmp);
  ans = calc(k);
  for (int i = 1; i < n; i++) {
    add(a[i].now, -1);
    ans += calc(a[i].num + k);
  }
  printf("%lld", ans);
}
