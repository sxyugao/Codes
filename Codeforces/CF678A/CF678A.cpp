#include <cstdio>
long long n, k;
int main(){
	scanf("%lld%lld", &n, &k);
	printf("%lld", (n / k + 1) * k);
}
