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
#undef gc
typedef unsigned long long ull;
const int N = 5e5 + 5;
const ull BASE = 101;
ull pw[N], h[N];
inline ull calc(int l, int r) { return h[r] - h[l - 1] * pw[r - l + 1]; }
bool not_pri[N];
int pri[N], nxt[N], a[N];
char s[N];
int main() {
  int n = read();
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * BASE;
  gets(s + 1);
  for (int i = 1; i <= n; i++) h[i] = h[i - 1] * BASE + s[i];
  for (int i = 2; i <= n; i++) {
    if (!not_pri[i]) {
      pri[++pri[0]] = i;
      nxt[i] = i;
    }
    for (int j = 1; j <= pri[0] && i * pri[j] <= n; j++) {
      not_pri[i * pri[j]] = 1;
      nxt[i * pri[j]] = pri[j];
      if (i % pri[j] == 0) break;
    }
  }
  scanf("%d", &n);
  while (n--) {
    int l = read(), r = read();
    int len = r - l + 1;
    if (calc(l + 1, r) == calc(l, r - 1)) {
      puts("1");
      continue;
    }
    a[0] = 0;
    while (len > 1) {
      a[++a[0]] = nxt[len];
      len = len / nxt[len];
    }
    len = r - l + 1;
    for (int i = 1; i <= a[0]; i++) {
      int tmp = len / a[i];
      if (calc(l, r - tmp) == calc(l + tmp, r)) len = tmp;
    }
    printf("%d\n", len);
  }
}