#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
const int N = 1e6 + 5;
const ull BASE = 233317;
ull tar, pw[N], h[N];
ull calc(int l, int r) { return h[r] - h[l - 1] * pw[r - l + 1]; }
char a[N], b[N], s[N];
int top;
int main() {
  scanf("%s%s", a + 1, b + 1);
  int len = strlen(b + 1);
  int n = strlen(a + 1);
  for (int i = 1; i <= len; i++) tar = tar * BASE + b[i];
  pw[0] = 1;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * BASE;
  for (int i = 1; i <= n; i++) {
    s[++top] = a[i];
    h[top] = h[top - 1] * BASE + a[i];
    if (top >= len && calc(top - len + 1, top) == tar) top -= len;
  }
  for (int i = 1; i <= top; i++) putchar(s[i]);
}