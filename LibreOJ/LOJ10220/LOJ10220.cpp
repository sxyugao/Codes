#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, P;
struct Matrix {
    int a[2][2];
    Matrix() { memset(a, 0, sizeof(a)); }
    void init() {
        for (int i = 0; i < 2; i++) a[i][i] = 1;
    }
    Matrix operator*(const Matrix &b) const {
        Matrix ans;
        for (int i = 0; i < 2; i++)
            for (int k = 0; k < 2; k++)
                for (int j = 0; j < 2; j++) {
                    ans.a[i][j] += 1LL * a[i][k] * b.a[k][j] % P;
                    ans.a[i][j] %= P;
                }
        return ans;
    }
    Matrix pow(int n) {
        Matrix ans, a = (*this);
        ans.init();
        while (n) {
            if (n & 1) ans = ans * a;
            a = a * a;
            n >>= 1;
        }
        return ans;
    }
};
int main() {
    scanf("%d%d", &n, &P);
    Matrix a;
    a.a[0][0] = a.a[0][1] = a.a[1][0] = 1;
    printf("%d\n", a.pow(n).a[0][1]);
}