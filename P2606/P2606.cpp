#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int pw(int a, int n, int P){
	int ans = 1;
	while(n) {
		if(n & 1) ans = 1LL * ans * a % P;
		a = 1LL * a * a % P;
		n >>= 1;
	}
	return ans;
}
const int MAXN = 1000005;
int n, P;
int l[MAXN], r[MAXN];
int siz[MAXN], f[MAXN], fac[MAXN], inv[MAXN];
int dfs(int k){
	if(k > n) return 0;
	l[k] = k << 1; r[k] = k << 1 | 1;
	if(l[k] > n) l[k] = 0;
	if(r[k] > n) r[k] = 0;
	return siz[k] = 1 + dfs(k << 1) + dfs(k << 1 | 1);
}
int C(int n, int m){
	return 1LL * fac[n] * inv[m] % P * inv[n - m] % P;
}
int dp(int k){
	if(!k) return 1;
	if(f[k]) return f[k];
	return f[k] = 1LL * dp(l[k]) * dp(r[k]) % P * C(siz[k] - 1, siz[l[k]]) % P;
}
int main(){
	n = read(), P = read();
	fac[0] = 1;
	for(int i = 1; i <= n; i++) fac[i] = 1LL * fac[i - 1] * i % P;
	inv[n] = pw(fac[n], P - 2, P);
	for(int i = n - 1; ~i; i--) inv[i] = 1LL * inv[i + 1] * (i + 1) % P;
	dfs(1);
	printf("%d", dp(1));
}
