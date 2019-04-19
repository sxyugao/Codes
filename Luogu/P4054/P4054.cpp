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
int n, m;
int lowbit(int x) { return x & -x; }
struct Tree {
    int tree[305][305];
    void add(int x, int y, int z) {
        for (int i = x; i <= n; i += lowbit(i))
            for (int j = y; j <= m; j += lowbit(j))
                tree[i][j] += z;
    }
    int query(int x, int y) {
        int ans = 0;
        for (int i = x; i; i -= lowbit(i))
            for (int j = y; j; j -= lowbit(j))
                ans += tree[i][j];
        return ans;
    }
    int query(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x2, y1 - 1) - query(x1 - 1, y2) + query(x1 - 1, y1 - 1);
    }
} c[105];
int a[305][305];
int main() {
    n = read(), m = read();
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            c[a[i][j] = read()].add(i, j, 1);
    for (int q = read(); q; q--) {
        int opt = read();
        if (opt == 1) {
            int x = read(), y = read(), z = read();
            c[a[x][y]].add(x, y, -1);
            a[x][y] = z;
            c[z].add(x, y, 1);
        } else {
            int x1 = read(), x2 = read(), y1 = read(), y2 = read(), x = read();
            printf("%d\n", c[x].query(x1, y1, x2, y2));
        }
    }
}