#include <bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, cnt, prob, penalty, curp, curt;
string s;
bool finished;
struct Submisson {
  bool sol;
  int num, t;
} res[N];
int gtn(int l, int r) { return stoi(s.substr(l, r - l + 1)); }
string gts(int l, int r) { return s.substr(l, r - l + 1); }
void dfs(int now, int type) {
  if (cnt > m) return;
  if (now > n) {
    if (curp == prob && curt == penalty) {
      cout << prob << " " << penalty;
      for (int i = 1; i <= cnt; i++) {
        cout << " ";
        if (res[i].sol) cout << res[i].t << " ";
        cout << res[i].num << " " << (res[i].num > 1 ? "tries" : "try");
      }
      cout << '\n';
      finished = 1;
    }
    return;
  }
  // prob
  if (type == 1) {
    prob = gtn(1, 1);
    dfs(2, 2);
    if (finished) return;
    if (isdigit(s[2])) {
      prob = gtn(1, 2);
      dfs(3, 2);
    }
    return;
  }
  int pos = now;
  // penalty
  if (type == 2) {
    while (pos < n && pos - now <= 3 && isdigit(s[pos + 1])) pos += 1;
    for (int i = now; i <= pos; i++) {
      penalty = gtn(now, i);
      dfs(i + 1, 3);
      if (finished) return;
    }
    return;
  }
  // submissons
  if (!isdigit(s[now])) return;
  while (pos < n && isdigit(s[pos + 1])) pos += 1;
  if (pos - now > 5) return;
  int nxt = pos + 1;
  while (nxt < n && islower(s[nxt + 1])) nxt += 1;
  string p = gts(pos + 1, pos + 3);
  bool tries = 0;
  if (p == "tri") tries = 1;
  // unaccepted
  int num = gtn(now, pos);
  if ((num == 1 && !tries) || (num > 1 && tries)) {
    if (s[now] != '0' && num <= 100) {
      res[++cnt] = {0, num, 0};
      dfs(nxt + 1, 3);
      if (finished) return;
      cnt -= 1;
    }
  }
  // accepted
  for (int i = now; i < pos; i++) {
    int t = gtn(now, i), num = gtn(i + 1, pos);
    if (s[i + 1] == '0') continue;
    if (num == 0) continue;
    if (tries && num == 1) continue;
    if (!tries && num > 1) continue;
    if (t >= 300) continue;
    if (num > 100) continue;
    curp += 1;
    curt += (num - 1) * 20 + t;
    res[++cnt] = {1, num, t};
    dfs(nxt + 1, 3);
    if (finished) return;
    curp -= 1;
    curt -= (num - 1) * 20 + t;
    cnt -= 1;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  int T;
  cin >> T >> m;
  while (T--) {
    cnt = finished = 0;
    curp = curt = 0;
    cin >> s;
    n = s.length();
    s = "#" + s;
    dfs(1, 1);
  }
}
