#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
map<string, int> m;
int main() {
  string name;
  int T, opt, x;
  cin >> T;
  while (T--) {
    cin >> opt;
    if (opt == 4)
      printf("%lu\n", m.size());
    else {
      cin >> name;
      if (opt == 1) {
        cin >> x;
        m[name] = x;
        puts("OK");
      }
      if (opt == 2) {
        if (m.count(name))
          printf("%d\n", m[name]);
        else
          puts("Not found");
      }
      if (opt == 3) {
        if (m.count(name)) {
          m.erase(m.find(name));
          puts("Deleted successfully");
        } else
          puts("Not found");
      }
    }
  }
}