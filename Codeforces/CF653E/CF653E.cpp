#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
typedef pair<int, int> Data;
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
const int N = 3e5 + 5;
bool used[N];
int n, m, k, pre[N], nxt[N];
set<Data> s;
inline void del(int x) {
  used[x] = 1;
  pre[nxt[x]] = pre[x];
  nxt[pre[x]] = nxt[x];
}
inline bool check(int x, int y) {
  if (x > y) swap(x, y);
  return !s.count(make_pair(x, y));
}
void dfs(int x) {
  vector<int> v;
  for (int y = nxt[1]; y <= n; y = nxt[y])
    if (check(x, y)) v.push_back(y);
  for (int t : v) del(t);
  for (int y : v) dfs(y);
}
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i <= n; i++) pre[i] = i - 1, nxt[i] = i + 1;
  int num = n - 1;
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    if (x > y) swap(x, y);
    if (x == 1) num--;
    s.insert(make_pair(x, y));
  }
  if (num < k) return puts("impossible"), 0;
  num = 0;
  used[1] = 1;
  for (int i = 2; i <= n; i++)
    if (check(1, i) && !used[i]) del(i), dfs(i), num++;
  if (nxt[1] <= n) return puts("impossible"), 0;
  if (num > k) return puts("impossible"), 0;
  puts("possible");
}
