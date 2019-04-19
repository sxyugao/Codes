#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
char ibuf[1 << 14], *p1 = ibuf, *p2 = ibuf;
inline char gc() {
    return p1 == p2 && (p2 = (p1 = ibuf) + fread(ibuf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
LL read() {
    LL x = 0, f = 1;
    char c = gc();
    for (; !isdigit(c); c = gc())
        if (c == '-') f = -1;
    for (; isdigit(c); c = gc()) x = x * 10 + c - '0';
    return x * f;
}
char obuf[1 << 14], *p = obuf;
void pc(char c) {
    if (obuf + (1 << 14) == p) {
        fwrite(obuf, 1, 1 << 14, stdout);
        p = obuf;
    }
    *p++ = c;
}
void write(int x) {
    if (x < 0) pc('-'), x = -x;
    if (x > 9) write(x / 10);
    pc(x % 10 ^ '0');
}
void writeln(int x) {
    write(x);
    pc('\n');
}
void fsh() {
    fwrite(obuf, 1, p - obuf, stdout);
}
const int N = 90;
LL g[N + 5] = {0, 1, 2};
int num, a[N + 5], f[N + 5][2];
int main() {
    for (int i = 3; i <= N + 1; i++) g[i] = g[i - 1] + g[i - 2];
    for (int T = read(); T; T--) {
        LL n = read();
        num = 0;
        for (int i = N; n; i--) {
            if (g[i] > n) continue;
            n -= g[i];
            a[++num] = i;
        }
        reverse(a + 1, a + num + 1);
        f[1][1] = 1, f[1][0] = (a[1] - 1) >> 1;
        for (int i = 2; i <= num; i++) {
            f[i][1] = f[i - 1][1] + f[i - 1][0];
            f[i][0] = f[i - 1][1] * ((a[i] - a[i - 1] - 1) / 2) + f[i - 1][0] * ((a[i] - a[i - 1]) / 2);
        }
        writeln(f[num][0] + f[num][1]);
    }
    fsh();
}