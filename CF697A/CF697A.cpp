#include <cstdio>
#include <iostream>
using namespace std;
int main() {
  int t, s, x;
  scanf("%d%d%d", &t, &s, &x);
  x -= t;
  puts(((x % s == 0 || x % s == 1) && x >= 0 && x != 1) ? "YES" : "NO");
}