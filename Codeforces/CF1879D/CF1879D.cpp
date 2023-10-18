#include <cstdio>
#include <iostream>
using namespace std;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
char gc() {
  return p1 == p2 &&
                 (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2)
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
const int P = 998244353;
const int N = 3e5 + 5;
int a[N];
int main() {
  int n = read();
  for (int i = 1; i <= n; ++i) a[i] = a[i - 1] ^ read();
  int ans = 0;
  for (int j = 0; j <= 30; ++j) {
    int sum[2] = {0, 0};
    int cnt[2] = {1, 0};
    for (int i = 1; i <= n; ++i) {
      bool t = (a[i] >> j) & 1;
      ans = (ans + 1LL * (1 << j) * cnt[!t] % P * i) % P;
      ans = (ans - 1LL * (1 << j) * sum[!t]) % P;
      ++cnt[t];
      sum[t] = (sum[t] + i) % P;
    }
  }
  printf("%d", (ans + P) % P);
}