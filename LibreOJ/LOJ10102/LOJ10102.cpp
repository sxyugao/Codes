#include <cstdio>
#include <cstring>
#include <iostream>
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
const int N = 3e4 + 5;
int nedge, head[N];
struct Edge {
    int to, nxt;
} edge[N << 1];
void add(int x, int y) {
    edge[++nedge].to = y;
    edge[nedge].nxt = head[x];
    head[x] = nedge;
}
int n, m, ans;
int tot, dfn[N], low[N];
void init() {
    nedge = tot = ans = 0;
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
}
bool input() {
    n = read(), m = read();
    if (!n && !m) return 0;
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read();
        add(x, y), add(y, x);
    }
    return 1;
}
void dfs(int x, int fa) {
    dfn[x] = low[x] = ++tot;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (y == fa) continue;
        if (!dfn[y]) {
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (low[y] > dfn[x]) ans++;
        } else {
            low[x] = min(low[x], dfn[y]);
        }
    }
}
int solve() {
    for (int i = 1; i <= n; i++)
        if (!dfn[i]) dfs(i, 0);
    return ans;
}
int main() {
    while (input()) {
        printf("%d\n", solve());
        init();
    }
}