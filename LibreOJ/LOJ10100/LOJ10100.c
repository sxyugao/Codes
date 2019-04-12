#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#define min(a, b) ((a) < (b) ? (a) : (b))
#define N 105
int nedge, head[N];
bool flag;
#define gc c = getchar()
int read() {
    int x = 0, f = 1;
    char gc;
    for (; !isdigit(c); gc)
        if (c == '-') f = -1;
    for (; isdigit(c); gc) x = x * 10 + c - '0';
    if (c == '\n') flag = 1;
    return x * f;
}
#undef gc
struct Edge {
    int to, nxt;
} edge[N * N];
void add(int x, int y) {
    edge[++nedge].to = y;
    edge[nedge].nxt = head[x];
    head[x] = nedge;
}
int n, m, ans;
int tot, dfn[N], low[N];
void init() {
    ans = tot = nedge = 0;
    memset(head, 0, sizeof(head));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
}
bool input() {
    n = read();
    if (!n) return 0;
    int x = 0, y = 0;
    while (x = read()) {
        flag = 0;
        while (y = read()) {
            add(x, y), add(y, x);
            if (flag) break;
        }
    }
    return 1;
}
void dfs(int x, int fa) {
    dfn[x] = low[x] = ++tot;
    int cnt = 0;
    bool cut = 0;
    for (int i = head[x]; i; i = edge[i].nxt) {
        int y = edge[i].to;
        if (!dfn[y]) {
            cnt++;
            dfs(y, x);
            low[x] = min(low[x], low[y]);
            if (!fa && cnt > 1) cut = 1;
            if (fa && low[y] >= dfn[x]) cut = 1;
        } else if (y != fa) {
            low[x] = min(low[x], dfn[y]);
        }
    }
    if (cut) ans++;
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