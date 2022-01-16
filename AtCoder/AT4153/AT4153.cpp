#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0;
  char gc;
  while (!isdigit(c)) gc;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x;
}
#undef gc
const int N = 1005;
int n, c, num[5][N], d[N][N];
int calc(int x, int y, int z) {
  int sum = 0;
  for (int j = 1; j <= c; j++)
    sum += d[j][x] * num[0][j] + d[j][y] * num[1][j] + d[j][z] * num[2][j];
  return sum;
}
int main() {
  n = read(), c = read();
  for (int i = 1; i <= c; i++)
    for (int j = 1; j <= c; j++) d[i][j] = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) num[(i + j) % 3][read()]++;
  int ans = 0x7fffffff;
  for (int i = 1; i <= c; i++)
    for (int j = 1; j <= c; j++)
      for (int k = 1; k <= c; k++) {
        if (i == j || k == j || i == k) continue;
        ans = min(ans, calc(i, j, k));
      }
  printf("%d", ans);
}