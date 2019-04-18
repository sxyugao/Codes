#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int P = 1e4;
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
struct Matrix {
    int a[2][2];
    Matrix() { memset(a, 0, sizeof(a)); }
    void init() {
        for (int i = 0; i < 2; i++) a[i][i] = 1;
    }
    Matrix operator*(const Matrix &b) {
        Matrix ans;
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++)
                for (int j = 0; j < 2; j++)
                    ans.a[i][j] = (ans.a[i][j] + a[i][k] * b.a[k][j]) % P;
        return ans;
    }
    Matrix pow(int n) {
        Matrix ans;
        Matrix a = *this;
        ans.init();
        while (n) {
            if (n & 1) ans = ans * a;
            a = a * a;
            n >>= 1;
        }
        return ans;
    }
} a;
int main() {
    int n;
    a.a[0][0] = 1;
    a.a[0][1] = 1;
    a.a[1][0] = 1;
    a.a[1][1] = 0;
    while (~(n = read()))
        printf("%d\n", a.pow(n).a[0][1]);
}