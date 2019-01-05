#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
#define gc c = getchar()
LL read(){
	LL x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int a[20];
LL f[20][2][5];
LL dp(int len, bool lim, int cnt){
	if(!len) return 1;
	if(f[len][lim][cnt]) return f[len][lim][cnt];
	int Max = lim ? a[len] : 9;
	LL ans = dp(len - 1, lim && Max == 0, cnt);
	if(cnt <= 2) {
		for(int i = 1; i <= Max; i++)
			ans += dp(len - 1, lim && i == Max, cnt + 1);
	}
	return f[len][lim][cnt] = ans;
}
LL solve(LL x){
	int len = 0;
	while(x) {
		a[++len] = x % 10;
		x /= 10;
	}
	memset(f, 0, sizeof(f));
	return dp(len, 1, 0);
}
int main(){
	for(int T = read(); T; T--) {
		LL x = read(), y = read();
		printf("%lld\n", solve(y) - solve(x - 1));
	}
}
