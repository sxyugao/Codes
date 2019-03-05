#include <cstdio>
#include <iostream>
using namespace std;
long long a, b, c, d;
int main() {
  scanf("%lld%lld%lld%lld", &a, &b, &c, &d);
  printf("%lld", max(a, c) * 2 + (b + d) * 2 + 4);
}