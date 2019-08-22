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
set<int> x, y;
multiset<int> a, b;
char opt[1];
int main() {
  int w = read(), h = read(), n = read();
  x.insert(0), x.insert(w), a.insert(w);
  y.insert(0), y.insert(h), b.insert(h);
  while (n--) {
    scanf("%s", opt);
    int p = read();
    if (*opt == 'V') {
      x.insert(p);
      iter it = x.find(p);
      iter l = --it, r = ++(++it);
      a.erase(a.find(*r - *l));
      a.insert(p - *l);
      a.insert(*r - p);
    } else {
      y.insert(p);
      iter it = y.find(p);
      iter l = --it, r = ++(++it);
      b.erase(b.find(*r - *l));
      b.insert(p - *l);
      b.insert(*r - p);
    }
    printf("%lld\n", 1LL * (*a.rbegin()) * (*b.rbegin()));
  }
}
