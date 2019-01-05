#include <cstdio>
typedef long long LL;
LL k, L, s, w, P;
LL pw(LL a, LL n){
	LL ans = 1;
	while(n) {
		if(n & 1) ans = ans * a % P;
		a = a * a % P;
		n >>= 1;
	}
	return ans;
}
int main(){
	scanf("%lld%lld%lld%lld%lld", &k, &L, &P, &s, &w);
	k %= P;
	if(L == 1) return printf("%lld", s ? 1 : k), 0;
	if(L == 2) return printf("%lld", (s ? 1 : k) * (k - 1) % P), 0;
	printf("%lld", (s ? 1 : k) * (k - 1) % P * pw(k - 2, L - 2) % P);
}
