#include <stdio.h>
#include <string.h>
typedef unsigned long long ull;
#define N 400000
const ull BASE = 101;
ull H[N + 5], pw[N + 5];
char s[N + 5];
ull Hash(int l, int r) { return H[r] - H[l - 1] * pw[r - l + 1]; }
int main() {
  pw[0] = 1;
  for (int i = 1; i <= N; i++) pw[i] = pw[i - 1] * BASE;
  while (~scanf("%s", s + 1)) {
    int len = strlen(s + 1);
    for (int i = 1; i <= len; i++) H[i] = H[i - 1] * BASE + s[i];
    for (int i = 1; i <= len; i++)
      if (Hash(1, i) == Hash(len - i + 1, len)) printf("%d ", i);
    puts("");
  }
}