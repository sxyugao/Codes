#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline int read() {
  int x = 0, f = 1;
  char c = gc();
  while (!isdigit(c)) c = gc();
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
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 1e5 + 5;
char s[N];
int n, q, nxt[N][2];
int tot, pre[N], ans[N * 10][10];
vector<int> v[N];
inline void del(int x) {
  nxt[nxt[x][0]][1] = nxt[x][1];
  nxt[nxt[x][1]][0] = nxt[x][0];
}
void run() {
  bool d = 1;
  for (int i = nxt[0][d];; i = nxt[i][d]) {
    if (v[i].empty()) pre[i] = nxt[i][0];
    v[i].emplace_back(++tot);
    if (!i) return run();
    if (i > n) return;
    for (int j = 0; j <= 9; j++) ans[tot][j] = ans[tot - 1][j];
    if (isdigit(s[i])) {
      ans[tot][s[i] ^ '0']++;
      if (s[i]-- == '0') del(i);
    } else {
      d = s[i] == '>';
      if (!isdigit(s[nxt[i][d]])) del(i);
    }
  }
}
inline int query(int p, int t) {
  auto x = lower_bound(v[p].begin(), v[p].end(), t);
  if (x == v[p].end()) return 0x7fffffff;
  return *x;
}
int main() {
  n = read(), q = read();
  for (int i = 1; i <= n; i++) s[i] = gc();
  nxt[0][1] = 1;
  for (int i = 0; i <= n; i++) nxt[i + 1][0] = i, nxt[i][1] = i + 1;
  run();
  while (q--) {
    int L = read(), R = read();
    int l = v[L][0], r = min(query(R + 1, l), query(pre[L], l));
    for (int i = 0; i <= 9; i++) write(ans[r - 1][i] - ans[l - 1][i]), pc(' ');
    pc('\n');
  }
  fsh();
}
