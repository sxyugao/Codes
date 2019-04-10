#include <bits/stdc++.h>
using namespace std;
#define gc c = getchar()
int read() {
    int x = 0, f = 1;
    char gc;
    for (; !isdigit(c); gc)
        if (c == '-') f = -1;
    for (; isdigit(c); gc) x = x * 10 + c - '0';
    return x * f;
}
#undef gc
const int N = 1e5 + 5;
const int M = 1e6 + 5;
int head[N];
struct Edge {
    int to, nxt;
} edge[M << 1];
int tot, dfn[N], low[N];
int scc, col[N], siz[N], in[N];
int top, stk[N];
bool vis[N];
map<pair<int, int>, bool> used;
vector<int> v[N];
void dfs(int x) {
    dfn[x] = low[x] = ++tot;
    stk[++top] = x;
    vis[x] = 1;
    int y;
    for (int i = head[x]; i; i = edge[i].nxt) {
        y = edge[i].to;
        if (!dfn[y]) {
            dfs(y);
            low[x] = min(low[x], low[y]);
        } else if (vis[y]) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (dfn[x] == low[x]) {
        scc++;
        do {
            y = stk[top--];
            col[y] = scc;
            siz[scc]++;
            vis[y] = 0;
        } while (x != y);
    }
}
int n, m, P, f[N], g[N];
void Add(int &x, int y) { x = x + y >= P ? x + y - P : x + y; }
int main() {
    n = read(), m = read(), P = read();
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        edge[i].to = y;
        edge[i].nxt = head[x];
        head[x] = i;
    }
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i);
    for (int x = 1; x <= n; x++) {
        for (int i = head[x]; i; i = edge[i].nxt) {
            int y = edge[i].to;
            if (col[x] == col[y]) continue;
            if (used[make_pair(col[x], col[y])]) continue;
            used[make_pair(col[x], col[y])] = 1;
            v[col[x]].push_back(col[y]);
            in[col[y]]++;
        }
    }
    queue<int> q;
    for (int i = 1; i <= scc; i++)
        if (!in[i]) {
            f[i] = siz[i];
            g[i] = 1;
            q.push(i);
        }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int y : v[x]) {
            if (f[x] + siz[y] == f[y]) Add(g[y], g[x]);
            if (f[x] + siz[y] > f[y]) {
                g[y] = g[x];
                f[y] = f[x] + siz[y];
            }
            in[y]--;
            if (!in[y]) q.push(y);
        }
    }
    int ans = 0, cnt = 0;
    for (int i = 1; i <= scc; i++) {
        if (f[i] == ans) Add(cnt, g[i]);
        if (f[i] > ans) {
            ans = f[i];
            cnt = g[i];
        }
    }
    printf("%d\n%d\n", ans, cnt);
}