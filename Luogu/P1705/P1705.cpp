#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int a[2705], f[35][2795];
int main(){
	int m = read(), r = read(), n = read();
	for(int i = 1; i <= m; i++) a[i] = read();
	f[0][0] = 1;
	for(int i = 1; i <= m; i++)
		for(int k = r; k >= 1; k--)
			for(int j = 2790; j >= a[i]; j--)
				f[k][j] += f[k - 1][j - a[i]];
	int ans = 0;
	for(int i = n + 1; i <= 2790; i++) ans += f[r][i];
	printf("%d", ans);
}
