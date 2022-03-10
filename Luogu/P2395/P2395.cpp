#include <cstdio>
#include <iostream>
#include <map>
#include <stack>
using namespace std;
const int N = 1e4 + 5;
map<int, string> p;
map<string, int> id;
string str, s, ans;
int top, stk[N];
stack<string> url;
int main() {
  id["[h1]"] = 1, id["[/h1"] = -1, p[1] = "# ", p[-1] = " #";
  id["[h2]"] = 2, id["[/h2"] = -2, p[2] = "## ", p[-2] = " ##";
  id["[i]"] = 3, id["[/i]"] = -3, p[3] = p[-3] = "*";
  id["[b]"] = 4, id["[/b]"] = -4, p[4] = p[-4] = "__";
  id["[url"] = 5, id["[img"] = 6, p[5] = "[", p[6] = "![";
  id["[/ur"] = -5, id["[/im"] = -6, p[-5] = p[-6] = "]";
  id["[quo"] = id["[/qu"] = 0, p[0] = "";
  while (getline(cin, str)) s += str + '\n';
  for (unsigned i = 0; i < s.size(); i++) {
    if (s[i] == '[') {
      str.clear();
      unsigned j = i;
      while (j < s.size() && s[j] != ']') str += s[j++];
      str += s[j++];
      int opt = id[str.substr(0, 4)];
      ans += p[opt];
      if (opt == 5 || opt == 6) {
        url.push(s.substr(i + 5, j - i - 6));
      } else if (!opt) {
        if (str[1] == '/') return puts("Match Error"), 0;
        unsigned h = 7, t = 6;
        while (j < s.size() && (t < 7 || str.substr(t - 7) != "[/quote]")) {
          str += s[j++];
          t++;
        }
        t -= 8;
        while (str[h] == '\n') h++;
        while (str[t] == '\n') t--;
        if (i > 0 && s[i - 1] != '\n') ans += '\n';
        ans += "> ";
        for (unsigned k = h; k <= t; k++) {
          if (k > h && str[k - 1] == '\n') ans += "> ";
          ans += str[k];
        }
        ans += '\n';
      }
      if (opt > 0) stk[++top] = opt;
      if (opt < 0) {
        if (!top || stk[top] + opt) return puts("Match Error"), 0;
        top--;
      }
      if (opt == -5 || opt == -6) {
        ans += '(' + url.top() + ')';
        url.pop();
      }
      i = j - 1;
    } else {
      ans += s[i];
    }
  }
  if (top) return puts("Unclosed Mark"), 0;
  cout << ans << endl;
}