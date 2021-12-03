#include <bits/stdc++.h>
using namespace std;
string s, _s;
char c[4] = {'\0', 'S', 'B', 'Q'};
map<char, int> lev;
void solve(int len) {
  int rest = len;
  for (int i = 0; i < len; i++) {
    _s += s[i];
    if (s[i] ^ '0' && (len - i - 1) % 4) _s += c[(len - i - 1) % 4];
    rest--;
    if (rest == 8) _s += 'Y';
    if (rest == 4) _s += 'W';
  }
  for (int i = 0; i < (int)_s.size() - 1;)
    (_s[i] == '0' && _s[i + 1] == '0') ? (void)_s.erase(i--, 1) : void(i++);
  for (unsigned i = 0; i < _s.size(); i++)
    if ((_s[i] == 'Y' || _s[i] == 'W') && _s[i - 1] == '0') _s.erase(i - 1, 1);
  for (unsigned i = 1; i < _s.size(); i++)
    if (!isdigit(_s[i]) && !isdigit(_s[i - 1]) && lev[_s[i]] < lev[_s[i - 1]])
      _s.erase(i, 1);
  while (_s.size() && *_s.rbegin() == '0') _s.pop_back();
  cout << _s;
}
int main() {
  lev['S'] = 0, lev['B'] = 1, lev['Q'] = 2, lev['W'] = 3, lev['Y'] = 4;
  cin >> s;
  int p = s.find('.'), cnt = 0;
  while (!isdigit(s[0]) && s[0] != '.') {
    if (s[0] == '-') cnt++;
    s.erase(0, 1);
  }
  while (s.size() && s[0] == '0') s.erase(0, 1);
  if ((~p && s.size() == 1) || !s.size()) return puts("0"), 0;
  if (cnt & 1) putchar('F');
  p = s.find('.');
  solve(~p ? p : s.size());
  if (p < 0 || p == (int)s.size() - 1) return 0;
  if (s[0] == '.') putchar('0');
  putchar('D');
  for (unsigned i = p + 1; i < s.size(); i++) putchar(s[i]);
}