#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[20];
long long f[20][20][2][2];
long long dfs(int len, int cnt, bool lim, bool zero, int num){
	if(!len) return cnt;
	if(~f[len][cnt][lim][zero]) return f[len][cnt][lim][zero];
	long long sum = 0;
	int Max = lim ? a[len] : 9;
	for(int i = 0; i <= Max; i++) {
		bool can = (i == num) && (!(zero && num == 0));
		sum += dfs(len - 1, cnt + can, lim && i == Max, zero && i == 0, num);
	}
	return f[len][cnt][lim][zero] = sum;
}
long long solve(int x, int num){
	memset(f, -1, sizeof(f));
	int len = 0;
	while(x) {
		a[++len] = x % 10;
		x /= 10;
	}
	return dfs(len, 0, 1, 1, num);
}
int main(){
	int n; scanf("%d", &n);
	for(int i = 0; i <= 9; i++)
		printf("%lld\n", solve(n, i));
}
