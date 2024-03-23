#include <bitset>
#include <iostream>
using namespace std;
bitset<50> s[50];
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    bitset<50> t;
    for (int i = 0; i < n; ++i) {
      int siz, x;
      cin >> siz;
      s[i].reset();
      for (int _ = 0; _ < siz; ++_) {
        cin >> x;
        s[i].set(x - 1);
      }
      t |= s[i];
    }
    int ans = 0;
    for (int ex = 0; ex < 50; ++ex)
      if (t[ex]) {
        bitset<50> tmp;
        for (int i = 0; i < n; ++i)
          if (!s[i][ex]) tmp |= s[i];
        if (tmp.count() > ans) ans = tmp.count();
      }
    cout << ans << endl;
  }
}