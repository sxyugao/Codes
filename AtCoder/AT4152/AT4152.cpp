#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, f[100005];
int main() {
  scanf("%d", &n);
  memset(f, 0x7f, sizeof(f));
  f[0] = 0;
  int a = 1, b = 1;
  for (int i = 1; i <= 7; i++) {
    a *= 6, b *= 9;
    for (int j = 1; j <= 100000; j++) {
      f[j] = min(f[j], f[j - 1] + 1);
      if (j >= a) f[j] = min(f[j], f[j - a] + 1);
      if (j >= b) f[j] = min(f[j], f[j - b] + 1);
    }
  }
  printf("%d", f[n]);
}