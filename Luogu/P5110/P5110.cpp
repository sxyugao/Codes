#include <cstdio>
#include <iostream>
using namespace std;
typedef unsigned long long ull;
namespace Data {
ull A, B, C;
void init(){
	scanf("%llu%llu%llu", &A, &B, &C);
}
ull rand(){
	A ^= A << 32, A ^= A >> 13, A ^= A << 1;
	ull t = A;
	A = B, B = C, C ^= t ^ A; return C;
}
}
const int P = 1e9 + 7;
const int MAXN = 32000;
struct Matrix {
	int a[2][2];
	Matrix operator*(const Matrix &b) const {
		Matrix ans;
		ans.a[0][0] = (1LL * a[0][0] * b.a[0][0] + 1LL * a[0][1] * b.a[1][0]) % P;
		ans.a[0][1] = (1LL * a[0][0] * b.a[0][1] + 1LL * a[0][1] * b.a[1][1]) % P;
		ans.a[1][0] = (1LL * a[1][0] * b.a[0][0] + 1LL * a[1][1] * b.a[1][0]) % P;
		ans.a[1][1] = (1LL * a[1][0] * b.a[0][1] + 1LL * a[1][1] * b.a[1][1]) % P;
		return ans;
	}
};
Matrix a[MAXN + 5], b[MAXN + 5];
int main(){
	Matrix s;
	s.a[0][0] = 233; s.a[0][1] = 666;
	s.a[1][0] = 1, s.a[1][1] = 0;
	a[0].a[0][0] = a[0].a[1][1] = 1;
	for(int i = 1; i <= MAXN; i++) a[i] = a[i - 1] * s;
	b[0] = a[0]; s = a[MAXN];
	for(int i = 1; i <= MAXN; i++) b[i] = b[i - 1] * s;
	int T; scanf("%d", &T);
	Data::init();
	int ans = 0;
	while(T--) {
		int n = (Data::rand() - 1) % (P - 1);
		ans ^= (b[n / MAXN] * a[n % MAXN]).a[0][0];
	}
	printf("%d", ans);
}
