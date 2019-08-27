#include <cstdio>
#include <cstring>
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
const int N = 55;
bool query(int x1, int y1, int x2, int y2) {
  printf("? %d %d %d %d\n", x1, y1, x2, y2);
  fflush(stdout);
  return read() ^ 1;
}
int n, a[N][N], b[N][N];
bool check(int a[N][N], int x, int y) {
  return (a[x][y] == a[x + 1][y + 2]) && (a[x + 1][y] == a[x + 1][y + 1] ||
                                          a[x][y + 1] == a[x + 1][y + 1] ||
                                          a[x][y + 1] == a[x][y + 2]);
}
bool chk() {
  for (int i = 1; i < n; i++)
    for (int j = 1; j < n - 1; j++)
      if (check(a, i, j) != check(b, i, j)) return check(a, i, j) == query(i, j, i + 1, j + 2);
}
int main() {
  n = read();
  memset(a, -1, sizeof(a));
  a[1][1] = 1, a[n][n] = 0, a[1][2] = 0;
  a[2][3] = query(1, 2, 2, 3), a[2][1] = query(2, 1, 2, 3) ^ a[2][3];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) {
      if (~a[i][j]) continue;
      if (i == 1) {
        a[i][j] = query(i, j - 2, i, j) ^ a[i][j - 2];
      } else if (j == 1) {
        a[i][j] = query(i - 2, j, i, j) ^ a[i - 2][j];
      } else {
        a[i][j] = query(i - 1, j - 1, i, j) ^ a[i - 1][j - 1];
      }
    }
  memcpy(b, a, sizeof(a));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if ((i + j) & 1) b[i][j] ^= 1;
  if (chk()) memcpy(a, b, sizeof(b));
  puts("!");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) putchar('0' ^ a[i][j]);
    puts("");
  }
}
