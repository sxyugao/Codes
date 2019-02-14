#include <bits/stdc++.h>
using namespace std;
bool vis[2005][2005];
int va, vb, vc;
void init() {
    memset(vis, 0, sizeof(vis));
    scanf("%d%d%d", &va, &vb, &vc);
}
struct Data {
    int a, b, nxt, k, step;
} q[5000005];
void print(int p) {
    int t = q[p].nxt;
    if (!t) return;
    print(t);
    printf("%d ", q[p].k);
}
bool nxt(int l, int &r, int a, int b, int opt) {
    if (vis[a][b]) return 0;
    r++;
    q[r].a = a, q[r].b = b, q[r].k = opt;
    q[r].nxt = l;
    vis[a][b] = 1;
    q[r].step = q[l].step + 1;
    if (q[r].b == vc) {
        printf("%d ", q[r].step);
        print(r), puts("");
    }
    return q[r].b == vc;
}
void solve() {
    q[1].a = q[1].b = q[1].k = q[1].nxt = q[1].step = 0;
    vis[0][0] = 1;
    int l = 0, r = 1;
    bool f = 0;
    while (l < r && !f) {
        l++;
        f |= nxt(l, r, va, q[l].b, 1);
        f |= nxt(l, r, q[l].a, vb, 2);
        f |= nxt(l, r, 0, q[l].b, 3);
        f |= nxt(l, r, q[l].a, 0, 4);
        int ta = q[l].a + q[l].b, tb = 0;
        if (ta > va) {
            tb = ta - va;
            ta = va;
        }
        f |= nxt(l, r, ta, tb, 5);
        ta = 0, tb = q[l].a + q[l].b;
        if (tb > vb) {
            ta = tb - vb;
            tb = vb;
        }
        f |= nxt(l, r, ta, tb, 6);
    }
}
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        solve();
    }
}