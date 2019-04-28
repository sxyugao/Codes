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
int nedge, head[N];
struct Edge {
    int to, nxt, w;
} edge[50 * N];
void add(int x, int y, int z) {
    edge[++nedge].to = y;
    edge[nedge].w = z;
    edge[nedge].nxt = head[x];
    head[x] = nedge;
}
int t[N];
bool vis[N];
int d[N];
struct Data {
    int d;
    int x;
    bool operator<(const Data &b) const {
        return d > b.d;
    }
};
priority_queue<Data> q;
int main() {
    int n = read(), m = read(), S = read(), T = read(), g = read(), v = read();
    for (int i = 1; i <= n; i++) {
        int h = read(), l = read();
        t[i] = v ? (l - h) / v + 1 : 0x7fffffff;
    }
    t[T] = 0x7fffffff;
    for (int i = 1; i <= m; i++) {
        int x = read(), y = read(), z = read();
        add(x, y, z), add(y, x, z);
    }
    memset(d, 0x3f, sizeof(d));
    d[S] = 0;
    q.push(Data{0, S});
    while (!q.empty()) {
        int x = q.top().x;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = head[x]; i; i = edge[i].nxt) {
            int y = edge[i].to;
            if (d[x] + edge[i].w < min(d[y], t[y])) {
                d[y] = d[x] + edge[i].w;
                if (!vis[y]) q.push(Data{d[y], y});
            }
        }
    }
    if (d[T] > g) return puts("wtnap wa kotori no oyatsu desu!"), 0;
    printf("%d\n", d[T]);
}