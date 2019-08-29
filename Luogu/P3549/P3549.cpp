#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
inline char _gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
char buf[1 << 14], *p = buf;
void pc(char c) {
  if (buf + (1 << 14) == p) {
    fwrite(buf, 1, 1 << 14, stdout);
    p = buf;
  }
  *p++ = c;
}
void fsh() {
  fwrite(buf, 1, p - buf, stdout);
}
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 1e5 + 5;
int nedge, head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
void add(int x, int y) {
  edge[++nedge].to = y;
  edge[nedge].nxt = head[x];
  head[x] = nedge;
}
int fa[N];
vector<int> son[N];
void dfs(int x, int f) {
  fa[x] = f;
  for (int i = head[x]; i; i = edge[i].nxt) {
    int y = edge[i].to;
    if (y == f) continue;
    dfs(y, x);
  }
}
bool isMmc[N];
void mmc(int x) {
  isMmc[x] = 1;
  int cnt = 0;
  for (int y : son[x]) {
    mmc(y);
    isMmc[x] &= isMmc[y];
    cnt += isMmc[y] && son[y].size() > 0;
  }
  isMmc[x] &= cnt <= 1;
}
int nxt[N], sum[N];
bool isC[N];
vector<int> ans;
void solveA(int x, bool p) {
  if (!p) {
    ans.emplace_back(x);
    for (int y : son[x])
      if (son[y].size() && y != nxt[x]) solveA(y, p ^ 1);
    for (int y : son[x])
      if (!son[y].size() && y != nxt[x]) ans.emplace_back(y);
  } else {
    for (int y : son[x])
      if (!son[y].size() && y != nxt[x]) ans.emplace_back(y);
    for (int y : son[x])
      if (son[y].size() && y != nxt[x]) solveA(y, p ^ 1);
    ans.emplace_back(x);
  }
}
void solveB(int x) {
  bool vis = 0;
  for (int y : son[x])
    if (!son[y].size() && y != nxt[x]) ans.emplace_back(y);
  for (int y : son[x])
    if (son[y].size() && y != nxt[x]) {
      solveA(y, vis);
      if (!vis) ans.emplace_back(x);
      vis ^= 1;
    }
}
int main() {
  int n = read();
  for (int i = 1; i < n; i++) {
    int x = read(), y = read();
    add(x, y), add(y, x);
  }
  dfs(1, 0);
  for (int i = n; i > 1; i = fa[i]) nxt[fa[i]] = i;
  for (int i = 1; i <= n; i++) son[fa[i]].emplace_back(i);
  mmc(1);
  for (int x = 1; x; x = nxt[x]) {
    isC[x] = 1;
    for (int y : son[x]) {
      if (y == nxt[x]) continue;
      if (!isMmc[y]) return puts("BRAK"), 0;
      sum[x] += bool(son[y].size());
      isC[x] = 0;
    }
    if (sum[x] > 2) return puts("BRAK"), 0;
  }
  bool hasC = 0;
  for (int x = 1; x; x = nxt[x]) {
    hasC |= isC[x];
    if (isC[x])
      ans.emplace_back(x);
    else if (sum[x] == 2 || x == n) {
      if (!hasC || (x == n && sum[x] == 2)) return puts("BRAK"), 0;
      if (sum[x] <= 1) {
        solveA(x, hasC);
      } else {
        solveB(x);
      }
      hasC = 0;
    } else {
      solveA(x, hasC);
    }
  }
  for (int x : ans) write(x), pc('\n');
  fsh();
}
