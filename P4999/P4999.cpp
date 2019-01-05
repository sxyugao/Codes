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
const int P = 1e9 + 7;
int a[20];
LL f[20][20][2];
void Add(LL &x, LL y){
	x = x + y >= P ? x + y - P : x + y;
}
LL dfs(int len, int cnt, bool lim, int num){
	if(!len) return cnt;
	if(~f[len][cnt][lim]) return f[len][cnt][lim];
	int Max = lim ? a[len] : 9;
	LL sum = 0;
	for(int i = 0; i <= Max; i++)
		Add(sum, dfs(len - 1, cnt + (i == num), lim && i == Max, num));
	return f[len][cnt][lim] = sum;
}
LL solve(LL x, int num){
	memset(f, -1, sizeof(f));
	int len = 0;
	while(x) {
		a[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 0, 1, num);
}
int main(){
	for(int T = read(); T; T--) {
		LL L = read(), R = read();
		LL ans = 0;
		for(int i = 1; i <= 9; i++) {
			int num = (solve(R, i) - solve(L - 1, i) + P) % P;
			Add(ans, 1LL * num * i % P);
		}
		printf("%lld\n", ans);
	}
}
