#include <cmath>
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
int f[25005][20];
int main(){
	int n = read(), T = read();
	for(int i = 1; i <= n; i++) f[i][0] = read();
	for(int j = 1; (1 << j) <= n; j++)
		for(int i = 1; i + (1 << j) - 1 <= n; i++)
			f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
	while(T--) {
		int l = read(), r = read();
		int k = log2(r - l + 1);
		printf("%d\n", min(f[l][k], f[r - (1 << k) + 1][k]));
	}
}
