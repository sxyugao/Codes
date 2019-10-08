#include <stdio.h>
int n;
int main() {
  scanf("%d", &n);
  puts(n & 1 ? "contest" : "home");
}