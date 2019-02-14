#include <cstdio>
#include <iostream>
using namespace std;
const int P = 10007;
int n, m, fac[P], inv[P];
int pw(int a, int n){
	a %= P;
	int ans = 1;
	while(n) {
		if(n & 1) ans = 1LL * ans * a % P;
		a = 1LL * a * a % P;
		n >>= 1;
	}
	return ans;
}
int C(int x, int y){
	if(x < y) return 0;
	if(x > P) return 1LL * C(x / P, y / P) * C(x % P, y % P) % P;
	return 1LL * fac[x] * inv[y] % P * inv[x - y] % P;
}
int main(){
	scanf("%d%d", &n, &m);
	fac[0] = 1;
	for(int i = 1; i < P; ++i) fac[i] = 1LL * fac[i - 1] * i % P;
	inv[P - 1] = pw(fac[P - 1], P - 2);
	for(int i = P - 2; ~i; --i) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
	printf("%lld", 1LL * C(n * m, n - 1) * pw(n, P - 2) % P);
}
