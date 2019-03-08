#include <stdbool.h>
#include <stdio.h>
int tot, trie[3000005][2];
void insert(int x) {
  int rt = 0;
  for (int i = 30; ~i; i--) {
    bool p = x & (1 << i);
    if (!trie[rt][p]) trie[rt][p] = ++tot;
    rt = trie[rt][p];
  }
}
int query(int x) {
  int ans = 0, rt = 0;
  for (int i = 30; ~i; i--) {
    bool p = x & (1 << i);
    if (trie[rt][p ^ 1]) {
      ans += (1 << i);
      rt = trie[rt][p ^ 1];
    } else {
      rt = trie[rt][p];
    }
  }
  return ans;
}
int main() {
  int n, x, ans = 0;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    int t = query(x);
    if (t > ans) ans = t;
    insert(x);
  }
  printf("%d", ans);
}