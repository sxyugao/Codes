#include <cstdio>
#include <iostream>
using namespace std;
int a, b, m;
int main() {
  scanf("%d%d%d", &a, &b, &m);
  int ans = 1;
  while (b) {
    if (b & 1) ans = 1LL * ans * a % m;
    a = 1LL * a * a % m;
    b >>= 1;
  }
  printf("%d", ans);
}