#include <cstdio>
int main(){
	int q;
	scanf("%d", &q);
	while(q--) {
		long long l, r;
		scanf("%lld%lld", &l, &r);
		long long L = l + r, R = r - l + 1;
		if(L & 1) R /= 2;
		else L /= 2;
		printf("%lld\n", L % 9 * R % 9);
	}
}
