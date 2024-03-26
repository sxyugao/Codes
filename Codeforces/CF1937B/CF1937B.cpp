#include <iostream>
using namespace std;
int main() {
  int T, n, l, r;
  string s1, s2;
  cin >> T;
  while (T--) {
    cin >> n;
    cin >> s1 >> s2;
    s1 += '2';
    l = r = 0;
    for (int i = 0; i < n; ++i) {
      if (s2[i] < s1[i + 1]) {
        r = i;
        break;
      }
      if (s2[i] > s1[i + 1]) {
        l = i + 1;
      }
    }
    cout << s1.substr(0, l + 1) + s2.substr(l) << endl;
    cout << r - l + 1 << endl;
  }
}