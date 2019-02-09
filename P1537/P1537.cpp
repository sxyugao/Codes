#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int m, a[10];
bool input() {
  m = 0;
  for (int i = 1; i <= 6; i++) {
    scanf("%d", &a[i]);
    m += a[i] * i;
  }
  return m;
}
void output(int T, bool can) {
  printf("Collection #%d:\n", T);
  printf("%s be divided.\n", can ? "Can" : "Can't");
  puts("");
}
bool f[60005];
int main() {
  for (int T = 1; input(); T++) {
    if (m & 1) {
      output(T, 0);
      continue;
    }
    memset(f, 0, sizeof(f));
    f[0] = 1;
    m /= 2;
    for (int i = 1; i <= 6; i++) {
      for (int k = 0; (1 << k) <= a[i]; k++) {
        for (int j = m; j >= (1 << k) * i; j--) f[j] |= f[j - (1 << k) * i];
        a[i] -= (1 << k);
      }
      for (int j = m; j >= a[i] * i; j--) f[j] |= f[j - a[i] * i];
    }
    output(T, f[m]);
  }
}