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
const int N = 20005;
int Abs(int x) {
    return x < 0 ? -x : x;
}
char opt[1];
int n, fa[N], d[N];
void init() {
    memset(d, 0, sizeof(d));
    for (int i = 1; i <= n; i++) fa[i] = i;
}
int find(int x) {
    if (fa[x] == x) return x;
    int f = fa[x];
    fa[x] = find(fa[x]);
    d[x] += d[f];
    return fa[x];
}
void merge(int x, int y) {
    fa[x] = y;
    d[x] = Abs(x - y) % 1000;
}
int query(int x) {
    find(x);
    return d[x];
}
int main() {
    for (int T = read(); T; T--) {
        n = read();
        init();
        while (scanf("%s", opt), *opt != 'O')
            if (*opt == 'E') {
                printf("%d\n", query(read()));
            } else {
                int x = read(), y = read();
                merge(x, y);
            }
    }
}