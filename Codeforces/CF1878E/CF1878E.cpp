#include <cctype>
#include <cstdio>
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
  return p1 == p2 &&
                 (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
inline int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
char obuf[1 << 14], *p = obuf;
inline void pc(char c) {
  if (obuf + (1 << 14) == p) {
    fwrite(obuf, 1, 1 << 14, stdout);
    p = obuf;
  }
  *p++ = c;
}
inline void fsh() { fwrite(obuf, 1, p - obuf, stdout); }
void write(int x) {
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
const int N = 2e5 + 5;
int a[N], lg2[N], st[N][20];
int main() {
  lg2[1] = 0;
  for (int i = 2; i < N; ++i) lg2[i] = lg2[i >> 1] + 1;
  int T = read();
  while (T--) {
    int n = read();
    for (int i = 1; i <= n; ++i) st[i][0] = read();
    for (int j = 1; j <= 17; ++j)
      for (int i = 1; i + (1 << j) - 1 <= n; ++i)
        st[i][j] = st[i][j - 1] & st[i + (1 << (j - 1))][j - 1];
    int q = read();
    while (q--) {
      int p = read(), k = read();
      if (st[p][0] < k) {
        pc('-'), pc('1'), pc(' ');
        continue;
      }
      int l = p, r = n;
      while (l < r) {
        int mid = (l + r + 1) >> 1;
        int t = lg2[mid - p + 1];
        if ((st[p][t] & st[mid - (1 << t) + 1][t]) >= k) {
          l = mid;
        } else {
          r = mid - 1;
        }
      }
      write(l), pc(' ');
    }
    pc('\n');
  }
  fsh();
}