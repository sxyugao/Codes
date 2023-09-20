#include <ctype.h>
#include <stdio.h>
char buf[1 << 14], *p1 = buf, *p2 = buf;
char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const int P = 80112002;
#define N 5005
#define M 500005
int nedge, head[N], to[M], nxt[M], in[N], out[N], f[N];
int dfs(int x) {
  if (!out[x]) f[x] = 1;
  if (!f[x]) {
    for (int i = head[x]; i; i = nxt[i]) {
      f[x] += dfs(to[i]);
      f[x] %= P;
    }
  }
  return f[x];
}
int main() {
  int n = read(), m = read();
  for (int i = 0; i < m; ++i) {
    int x = read(), y = read();
    nxt[++nedge] = head[y];
    to[nedge] = x;
    head[y] = nedge;
    ++in[x], ++out[y];
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i)
    if (!in[i]) {
      ans += dfs(i);
      ans %= P;
    }
  printf("%d", ans);
}