#include <cstdio>
#include <iostream>
#include <queue>
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
#define pc putchar
void write(int x) {
  if (x < 0) pc('-'), x = -x;
  if (x > 9) write(x / 10);
  pc(x % 10 ^ '0');
}
void writeln(int x) {
  write(x), pc('\n');
}
const int N = 1e5 + 5;
int head[N];
struct Edge {
  int to, nxt;
} edge[N << 1];
int in[N], f[N];
int main() {
  int n = read(), m = read();
  for (int i = 1; i <= m; i++) {
    int x = read(), y = read();
    in[y]++;
    edge[i].to = y;
    edge[i].nxt = head[x];
    head[x] = i;
  }
  queue<int> q;
  for (int i = 1; i <= n; i++)
    if (!in[i]) q.push(i), f[i] = 1;
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      f[y] = max(f[y], f[x] + 1);
      in[y]--;
      if (!in[y]) q.push(y);
    }
  }
  for (int i = 1; i <= n; i++) writeln(f[i]);
}
