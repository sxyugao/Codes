#include <cstdio>
int main(){
	long long l, r;
	scanf("%lld%lld", &l, &r);
	puts("YES");
	for(long long i = l; i < r; i += 2)
		printf("%lld %lld\n", i, i + 1);
}
