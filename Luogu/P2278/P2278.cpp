#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
struct Data {
  int id, t, exec, priority;
  bool operator<(const Data &b) const {
    if (priority != b.priority) return priority < b.priority;
    return t > b.t;
  }
  bool input() { return ~scanf("%d%d%d%d", &id, &t, &exec, &priority); }
};
priority_queue<Data> q;
int main() {
  Data x;
  int T = 0;
  while (x.input()) {
    while (!q.empty() && T + q.top().exec <= x.t) {
      T += q.top().exec;
      printf("%d %d\n", q.top().id, T);
      q.pop();
    }
    if (!q.empty()) {
      Data lst = q.top();
      q.pop();
      lst.exec -= x.t - T;
      q.push(lst);
    }
    q.push(x);
    T = x.t;
  }
  while (!q.empty()) {
    Data now = q.top();
    q.pop();
    T += now.exec;
    printf("%d %d\n", now.id, T);
  }
}