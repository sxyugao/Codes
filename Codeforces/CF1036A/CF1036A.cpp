#include <cstdio>
int main(){
	long long a, b;
	scanf("%lld%lld", &a, &b);
	printf("%lld", (b + a - 1) / a);
}
