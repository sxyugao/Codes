#include <cstdio>
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
const int MAXN = 200005;
const int P = 10007;
int n, Ans, ans, a[MAXN];
int nedge, head[MAXN];
struct Edge {
    int to, nxt;
} edge[MAXN * 2];
void add(int x, int y) {
    edge[++nedge].to = y;
    edge[nedge].nxt = head[x];
    head[x] = nedge;
}
void calc(int k) {
    int Max = 0, Maxx = 0, sum = 0;
    for (int i = head[k]; i; i = edge[i].nxt) {
        int u = edge[i].to;
        if (a[u] > Max) {
            Maxx = Max;
            Max = a[u];
        } else if (a[u] > Maxx)
            Maxx = a[u];
        sum = (sum + a[u]) % P;
    }
    for (int i = head[k]; i; i = edge[i].nxt) {
        int u = edge[i].to;
        ans = (ans + (sum - a[u]) * a[u]) % P;
    }
    Ans = max(Ans, Max * Maxx);
}
int main() {
    int n = read();
    for (int i = 1; i < n; i++) {
        int x = read(), y = read();
        add(x, y);
        add(y, x);
    }
    for (int i = 1; i <= n; i++) a[i] = read();
    for (int i = 1; i <= n; i++) calc(i);
    printf("%d %d", Ans, (ans + P) % P);
}