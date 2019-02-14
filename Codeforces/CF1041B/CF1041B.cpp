#include <cstdio>
typedef long long LL;
LL GCD(LL a, LL b){
	return b ? GCD(b, a % b) : a;
}
LL min(LL a, LL b){
	return a < b ? a : b;
}
int main(){
	LL a, b, x, y;
	scanf("%lld%lld%lld%lld", &a, &b, &x, &y);
	LL gcd = GCD(x, y);
	x /= gcd; y /= gcd;
	printf("%lld", min(a / x, b / y));
}
