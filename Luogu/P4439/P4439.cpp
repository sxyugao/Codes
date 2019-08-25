#include <cstdio>
#include <iostream>
using namespace std;
int n, ans;
char ch, lst;
int main() {
  scanf("%d", &n);
  while (n--) {
    scanf(" %c", &ch);
    if (lst != ch) ans++;
    lst = ch;
  }
  printf("%d", ans + 1);
}