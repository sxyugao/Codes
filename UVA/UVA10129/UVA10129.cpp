#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[26][26], in[26], out[26];
bool vis[26][26];
void init() {
  memset(a, 0, sizeof(a));
  memset(in, 0, sizeof(in));
  memset(vis, 0, sizeof(vis));
  memset(out, 0, sizeof(out));
}
void dfs(int x) {
  for (int y = 0; y < 26; y++)
    if (a[x][y] && !vis[x][y]) {
      vis[x][y] = 1;
      dfs(y);
    }
}
char s[1000];
int main() {
  int T, n;
  scanf("%d", &T);
  while (T--) {
    init();
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
      scanf("%s", s);
      int len = strlen(s);
      int x = s[0] - 'a', y = s[len - 1] - 'a';
      a[x][y] = 1;
      in[y]++, out[x]++;
    }
    int cnt = 0, S = -1, T = -1;
    for (int i = 0; i < 26; i++) {
      if (in[i] != out[i]) cnt++;
      if (in[i] + 1 == out[i]) S = i;
      if (in[i] == out[i] + 1) T = i;
    }
    bool f = 1;
    if (!cnt) {
      for (int i = 0; i < 26; i++) {
        bool flag = 0;
        for (int j = 0; j < 26; j++)
          if (a[i][j]) {
            dfs(i);
            flag = 1;
            break;
          }
        if (flag) break;
      }
    } else {
      if (cnt != 2 || S < 0 || T < 0) {
        f = 0;
      } else {
        dfs(S);
      }
    }
    for (int i = 0; i < 26 && f; i++)
      for (int j = 0; j < 26 && f; j++)
        if (a[i][j] && !vis[i][j]) {
          f = 0;
          break;
        }
    puts(f ? "Ordering is possible." : "The door cannot be opened.");
  }
}