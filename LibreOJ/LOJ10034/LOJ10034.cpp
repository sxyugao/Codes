#include <cstdio>
#include <iostream>
#include <map>
using namespace std;
map<string, bool> has;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    if (s == "add") {
      getline(cin, s);
      has[s] = 1;
    } else {
      getline(cin, s);
      puts(has[s] ? "yes" : "no");
    }
  }
}