#include <cmath>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
char buf[1 << 14], *p1 = buf, *p2 = buf;
inline char gc() {
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
inline string getline() {
  string s;
  char c;
  while (c = gc(), c != '\n') {
    s.push_back(c);
    if (c == '<') {
      s.pop_back();
      if (s.size()) s.pop_back();
    }
  }
  return s;
}
string s;
vector<string> a, b;
int main() {
  do {
    s = getline();
    a.push_back(s);
  } while (s != "EOF");
  do {
    s = getline();
    b.push_back(s);
  } while (s != "EOF");
  int t = 0;
  char c = gc();
  for (; isdigit(c); c = gc()) t = t * 10 + c - '0';
  int cnt = min(a.size(), b.size()) - 1;
  int ans = 0;
  for (int i = 0; i < cnt; i++) {
    int num = min(a[i].size(), b[i].size());
    for (int j = 0; j < num; j++)
      ans += a[i][j] == b[i][j];
  }
  printf("%d", (int)round(60.0 * ans / t));
}
