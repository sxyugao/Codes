#include <cstdio>
#include <iostream>
#include <queue>
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
const int N = 1e5 + 5;
int ans, t[N], cnt[N];
queue<int> q;
vector<int> v[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; i++) {
    t[i] = read();
    for (int num = read(); num; num--) {
      int x = read();
      if (!cnt[x]) ans++;
      cnt[x]++;
      v[i].emplace_back(x);
    }
    while (q.size() && t[i] - t[q.front()] >= 86400) {
      for (int x : v[q.front()]) {
        cnt[x]--;
        if (!cnt[x]) ans--;
      }
      q.pop();
    }
    q.push(i);
    write(ans), pc('\n');
  }
  fsh();
}
