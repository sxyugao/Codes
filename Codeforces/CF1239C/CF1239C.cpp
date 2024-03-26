#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
char gc() {
  static char buf[1 << 14], *p1 = buf, *p2 = buf;
  return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)
             ? EOF
             : *p1++;
}
int read() {
  int x = 0;
  char c = gc();
  while (!isdigit(c)) c = gc();
  for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
  return x;
}
const int N = 1e5;
struct Data {
  int t, id;
  bool operator<(const Data &b) const {
    return t > b.t || (t == b.t && id > b.id);
  }
};
priority_queue<Data> q;
queue<int> pending;
priority_queue<int, vector<int>, greater<int>> want;
long long ans[N];
int main() {
  int n = read(), p = read();
  for (int _ = 0; _ < n; ++_) {
    int t = read();
    q.push(Data{t, _});
  }
  long long now_time = 0;
  for (int _ = 0; _ < n; ++_) {
    if (pending.empty() && want.empty()) now_time = q.top().t;
    now_time += p;
    while (!q.empty() && q.top().t <= now_time) {
      int id = q.top().id;
      if (pending.empty() || pending.back() > id)
        pending.push(id);
      else
        want.push(id);
      q.pop();
    }
    ans[pending.front()] = now_time;
    pending.pop();
    if (pending.empty() && !want.empty()) {
      pending.push(want.top());
      want.pop();
    }
  }
  for (int _ = 0; _ < n; ++_) printf("%lld ", ans[_]);
}