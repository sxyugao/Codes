#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;
int nedge, head[2005];
struct Edge {
  int to, nxt;
} edge[2000005];
int in[2005];
void add(int x, int y) {
  edge[++nedge].nxt = head[x];
  edge[nedge].to = y;
  head[x] = nedge;
  in[y]++;
}
int fa[2005], ans[2005];
int Find(int x) { return x == fa[x] ? x : fa[x] = Find(fa[x]); }
queue<int> q;
char s[1005][1005];
int main() {
  int n, m;
  scanf("%d%d\n", &n, &m);
  for (int i = 1; i <= n + m; i++) fa[i] = i;
  for (int i = 1; i <= n; i++) gets(s[i] + 1);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '=') fa[Find(i)] = Find(n + j);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '>') add(Find(j + n), Find(i));
      if (s[i][j] == '<') add(Find(i), Find(j + n));
    }
  for (int i = 1; i <= n + m; i++)
    if (Find(i) == i && !in[i]) {
      q.push(i);
      ans[i] = 1;
    }
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = head[x]; i; i = edge[i].nxt) {
      int y = edge[i].to;
      ans[y] = max(ans[x] + 1, ans[y]);
      in[y]--;
      if (!in[y]) q.push(y);
    }
  }
  for (int i = 1; i <= n + m; i++)
    if (Find(i) == i && in[i]) return puts("No"), 0;
  puts("Yes");
  for (int i = 1; i <= n; i++) printf("%d ", ans[Find(i)]);
  puts("");
  for (int i = 1; i <= m; i++) printf("%d ", ans[Find(i + n)]);
}