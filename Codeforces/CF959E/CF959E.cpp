#include <cstdio>
#include <iostream>
typedef long long LL;
LL n;
int main(){
	scanf("%lld", &n);
	LL ans = 0;
	for(LL i = 1; i < n; i <<= 1)
		ans += ((n - i - 1) / (i << 1) + 1) * i;
	printf("%lld", ans);
}
