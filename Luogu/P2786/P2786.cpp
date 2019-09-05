#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline char gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
void readInt(int &x) {
  x = 0;
  bool f = 0;
  char c = gc();
  for (; !isdigit(c); c = gc())
    if (c == '-') f = -1;
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  if (f) x *= -1;
}
bool readStr(char *s) {
  char c = gc();
  while (!isalpha(c) && !isdigit(c) && c != EOF) c = gc();
  if (c == EOF) return 0;
  while (isalpha(c) || isdigit(c)) *s++ = c, c = gc();
  *s++ = '\0';
  return 1;
}
const int N = 1e5 + 5;
struct Data {
  Data(int _x = 0, char *_s = new char[55]) { x = _x, s = _s; }
  int x;
  char *s;
  void input() {
    s = new char[55];
    readStr(s);
    readInt(x);
  }
  bool operator<(const Data &b) const {
    return strcmp(s, b.s) < 0;
  }
} a[N];
int n, P;
char s[55];
void Add(int &x, int y) {
  x = x + y >= P ? x + y - P : x + y;
}
int main() {
  readInt(n), readInt(P);
  for (int i = 1; i <= n; i++) a[i].input();
  sort(a + 1, a + n + 1);
  int ans = 0;
  while (readStr(s)) {
    int p = lower_bound(a + 1, a + n + 1, Data(0, s)) - a;
    if (strcmp(a[p].s, s) == 0) Add(ans, a[p].x);
  }
  printf("%d", ans);
}
