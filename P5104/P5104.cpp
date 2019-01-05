#include <cstdio>
typedef long long LL;
const int P = 1e9 + 7;
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
	LL w, n, k;
	scanf("%lld%lld%lld", &w, &n, &k);
	n = pw(2, k);
	printf("%lld", w * pw(n, P - 2) % P);
}
