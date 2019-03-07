#include <climits>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[100005];
int main() {
  long long l, r;
  int n, len;
  scanf("%lld%lld%d", &l, &r, &n);
  while (n--) {
    scanf("%s", s);
    len = strlen(s);
    if (len == 1) {
      if (s[0] == '-') {
        puts("1");
        continue;
      }
    } else {
      if (s[0] == '0') {
        puts("1");
        continue;
      }
      if (s[0] == '-' && s[1] == '0') {
        puts("1");
        continue;
      }
    }
    int st = s[0] == '-';
    if (len - st > 19) {
      puts("2");
      continue;
    }
    unsigned long long x = 0;
    long long ans = 0;
    for (int i = st; s[i]; i++) x = x * 10 + s[i] - '0';
    if (!st && x > LLONG_MAX) {
      puts("2");
      continue;
    }
    if (st && x > (unsigned long long)LLONG_MAX + 1) {
      puts("2");
      continue;
    }
    if (st) {
      ans = -x;
    } else {
      ans = x;
    }
    puts(l <= ans && ans <= r ? "0" : "2");
  }
}