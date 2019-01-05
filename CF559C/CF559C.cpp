#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int P = 1e9 + 7;
LL pw(LL a, LL n){
	LL ans = 1;
	for(; n; a = a * a % P, n >>= 1)
		if(n & 1) ans = ans * a % P;
	return ans;
}
struct Point {
	int x, y;
	bool operator<(const Point &b) const {
		if(x != b.x) return x < b.x;
		return y < b.y;
	}
} a[2005];
LL fac[200005], inv[200005];
LL C(LL n, LL m){
	return fac[m] * inv[n] % P * inv[m - n] % P;
}
LL f[2005];
int main(){
	int h = read(), w = read(), n = read();
	for(int i = 1; i <= n; i++) a[i].x = read(), a[i].y = read();
	a[++n].x = h, a[n].y = w;
	sort(a + 1, a + n + 1);
	fac[0] = 1;
	for(int i = 1; i <= h + w; i++) fac[i] = fac[i - 1] * i % P;
	inv[h + w] = pw(fac[h + w], P - 2);
	for(int i = h + w - 1; ~i; i--) inv[i] = inv[i + 1] * (i + 1) % P;
	for(int i = 1; i <= n; i++) {
		f[i] = C(a[i].x - 1, a[i].x + a[i].y - 2);
		for(int j = 1; j < i; j++)
			if(a[j].y <= a[i].y) {
				f[i] -= f[j] * C(a[i].y - a[j].y, a[i].x + a[i].y - a[j].x - a[j].y) % P;
				f[i] = (f[i] + P) % P;
			}
	}
	printf("%lld", f[n]);
}
