#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
#define gc c = getchar()
int read() {
  int x = 0, f = 1;
  char gc;
  for (; !isdigit(c); gc)
    if (c == '-') f = -1;
  for (; isdigit(c); gc) x = x * 10 + c - '0';
  return x * f;
}
#undef gc
typedef set<int>::iterator iter;
set<int> s;
int main() {
  for (int T = read(); T; T--) {
    int opt = read(), x = read();
    if (opt == 1) {
      if (!s.insert(x).second) puts("Already Exist");
    } else {
      if (s.empty()) {
        puts("Empty");
        continue;
      }
      iter it = s.lower_bound(x);
      if (*it == x || it == s.begin()) {
        printf("%d\n", *it);
        s.erase(it);
      } else {
        if (it == s.end()) {
          printf("%d\n", *(--it));
          s.erase(it);
          continue;
        }
        int a = *it, b = *(--it);
        if (x - b > a - x) {
          printf("%d\n", a);
          s.erase(++it);
        } else {
          printf("%d\n", b);
          s.erase(it);
        }
      }
    }
  }
}