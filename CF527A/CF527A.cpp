#include <cstdio>
#include <iostream>
using namespace std;
long long x, y;
int main(){
	scanf("%lld%lld", &x, &y);
	long long ans = 0;
	while(x && y) {
		if(x < y) swap(x, y);
		ans += x / y;
		x %= y;
	}
	printf("%lld", ans);
}
