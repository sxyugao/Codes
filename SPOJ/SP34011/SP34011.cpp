#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int T, a, b, c;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf("%d%d%d", &a, &b, &c);
    printf("Case %d: %lld\n", i, 1LL * (b + 1) * b / 2 * (c + 1) * c / 2 * a);
  }
}