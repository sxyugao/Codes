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
int main() {
    int n = read(), L = read(), G = read();
    for (int i = 1; i <= n; i++) {
        int W = read(), H = read();
        while (W > G || H > G) W >>= 1, H >>= 1;
        if (min(W, H) < L) {
            puts("Too Young");
            continue;
        }
        puts(W == H ? "Sometimes Naive" : "Too Simple");
    }
}