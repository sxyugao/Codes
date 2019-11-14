#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, m;
char s[260];
int main() {
  scanf("%d%s", &m, s);
  n = strlen(s);
  for (int i = 0; i < n; i++) {
    putchar(' ');
    for (int j = 0; j < m; j++) putchar("- -- -----"[s[i] ^ '0']);
    printf(n - 1 != i ? "  " : "\n");
  }
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++) {
      putchar("|   ||| ||"[s[i] - '0']);
      for (int k = 0; k < m; k++) putchar(' ');
      putchar("|||||  |||"[s[i] - '0']);
      putchar("\n "[bool(s[i + 1])]);
    }
  for (int i = 0; i < n; i++) {
    putchar(' ');
    for (int j = 0; j < m; j++) putchar("  ----- --"[s[i] ^ '0']);
    printf(n - 1 != i ? "  " : "\n");
  }
  for (int j = 0; j < m; j++)
    for (int i = 0; i < n; i++) {
      putchar("| |   | | "[s[i] - '0']);
      for (int k = 0; k < m; k++) putchar(' ');
      putchar("|| |||||||"[s[i] - '0']);
      putchar("\n "[bool(s[i + 1])]);
    }
  for (int i = 0; i < n; i++) {
    putchar(' ');
    for (int j = 0; j < m; j++) putchar("- -- -- --"[s[i] ^ '0']);
    printf(n - 1 != i ? "  " : "\n");
  }
}
