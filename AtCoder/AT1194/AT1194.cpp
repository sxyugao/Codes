#include <cstdio>
#include <iostream>
using namespace std;
long long n, ans, Ans[2000];
long long calc(long long x){
	long long ans = x;
	while(x) {
		ans += x % 10;
		x /= 10;
	}
	return ans;
}
int main(){
	scanf("%lld", &n);
	for(long long i = max(1LL, n - 200); i <= n; i++)
		if(calc(i) == n) Ans[++ans] = i;
	printf("%lld\n", ans);
	for(int i = 1; i <= ans; i++) printf("%lld\n", Ans[i]);
}
