#include <cstdio>
#include <iostream>
using namespace std;
main() {
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  a %= (b + c);
  puts((a && a <= b) ? "Ant" : "Bug");
}