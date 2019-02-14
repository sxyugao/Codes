#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
using namespace std;
struct Queue {
  Queue() {}
  Queue(string S, string Opt) {
    s = S;
    opt = Opt;
  }
  string s, opt;
};
queue<Queue> q;
map<string, bool> vis;
string t, tar;
void print(string ans) {
  cout << ans.size() << endl;
  for (int i = 0; i < (int)ans.size(); i++) {
    cout << ans[i];
    if ((i + 1) % 60 == 0) cout << endl;
  }
}
int main() {
  for (int i = 0; i < 4; i++) {
    char ch;
    cin >> ch;
    tar += ch;
  }
  for (int i = 0; i < 4; i++) {
    char ch;
    cin >> ch;
    t = ch + t;
  }
  tar += t;
  if (tar == "12348765") return cout << "0" << endl, 0;
  q.push(Queue("12348765", ""));
  vis["12348765"] = 1;
  while (!q.empty()) {
    Queue now = q.front();
    q.pop();
    t.clear();
    for (int i = 0; i < 4; i++) t += now.s[i + 4];
    for (int i = 0; i < 4; i++) t += now.s[i];
    if (!vis[t]) {
      vis[t] = 1;
      q.push(Queue(t, now.opt + 'A'));
    }
    if (t == tar) return print(now.opt + 'A'), 0;
    t.clear();
    t += now.s[3];
    for (int i = 0; i < 3; i++) t += now.s[i];
    t += now.s[7];
    for (int i = 4; i < 7; i++) t += now.s[i];
    if (!vis[t]) vis[t] = 1, q.push(Queue(t, now.opt + 'B'));
    if (t == tar) return print(now.opt + 'B'), 0;
    t.clear();
    t += now.s[0], t += now.s[5], t += now.s[1], t += now.s[3];
    t += now.s[4], t += now.s[6], t += now.s[2], t += now.s[7];
    if (!vis[t]) vis[t] = 1, q.push(Queue(t, now.opt + 'C'));
    if (t == tar) return print(now.opt + 'C'), 0;
  }
}