#include <cstdio>
#include <iostream>
using namespace std;
const int N = 1e5 + 5;
const int INF = 0x3fffffff;
struct Splay {
  int rt, tot, cnt[N], siz[N], fa[N], a[N], son[N][2];
  bool chk(int x) { return son[fa[x]][1] == x; }
  void pushup(int x) { siz[x] = siz[son[x][0]] + siz[son[x][1]] + cnt[x]; }
  void rotate(int x) {
    int a = fa[x], b = fa[a], p = chk(x), q = son[x][p ^ 1];
    son[a][p] = q, fa[q] = a;
    son[b][chk(a)] = x, fa[x] = b;
    son[x][p ^ 1] = a, fa[a] = x;
    pushup(a), pushup(x);
  }
  void splay(int x, int tar = 0) {
    while (fa[x] != tar) {
      int f1 = fa[x], f2 = fa[f1];
      if (f2 != tar) rotate(chk(x) == chk(f1) ? f1 : x);
      rotate(x);
    }
    if (!tar) rt = x;
  }
  void insert(int v) {
    int cur = rt, p = 0;
    while (cur && a[cur] != v) {
      p = cur;
      cur = son[cur][v > a[cur]];
    }
    if (cur) {
      cnt[cur]++;
    } else {
      cur = ++tot;
      if (p) son[p][v > a[p]] = cur;
      son[cur][0] = son[cur][1] = 0;
      a[cur] = v, fa[cur] = p;
      cnt[cur] = siz[cur] = 1;
    }
    splay(cur);
  }
  void find(int x) {
    int cur = rt;
    while (son[cur][x > a[cur]] && x != a[cur]) cur = son[cur][x > a[cur]];
    splay(cur);
  }
  int kth(int k) {
    int cur = rt;
    while (1) {
      if (son[cur][0] && k <= siz[son[cur][0]]) {
        cur = son[cur][0];
      } else if (k > siz[son[cur][0]] + cnt[cur]) {
        k -= siz[son[cur][0]] + cnt[cur];
        cur = son[cur][1];
      } else {
        break;
      }
    }
    return a[cur];
  }
  int rank(int v) {
    find(v);
    return siz[son[rt][0]];
  }
  int pre(int v, bool k = 1) {
    find(v);
    if (a[rt] < v) {
      if (k) return rt;
      return a[rt];
    }
    int cur = son[rt][0];
    while (son[cur][1]) cur = son[cur][1];
    if (k) return cur;
    return a[cur];
  }
  int succ(int v, bool k = 1) {
    find(v);
    if (a[rt] > v) {
      if (k) return rt;
      return a[rt];
    }
    int cur = son[rt][1];
    while (son[cur][0]) cur = son[cur][0];
    if (k) return cur;
    return a[cur];
  }
  void remove(int v) {
    int lst = pre(v), nxt = succ(v);
    splay(lst), splay(nxt, lst);
    int del = son[nxt][0];
    if (cnt[del] > 1) {
      cnt[del]--;
      splay(del);
      return;
    }
    son[nxt][0] = 0;
  }
} splay;
int n, opt, x;
int main() {
  splay.insert(INF);
  splay.insert(-INF);
  scanf("%d", &n);
  while (n--) {
    scanf("%d%d", &opt, &x);
    if (opt == 1) splay.insert(x);
    if (opt == 2) splay.remove(x);
    if (opt == 3) printf("%d\n", splay.rank(x));
    if (opt == 4) printf("%d\n", splay.kth(x + 1));
    if (opt == 5) printf("%d\n", splay.pre(x, 0));
    if (opt == 6) printf("%d\n", splay.succ(x, 0));
  }
}