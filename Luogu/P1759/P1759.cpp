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
int a[205], b[205], c[205];
int f[205][205][205], g[205][205][205], lst[205][205][205];
void print(int n, int m, int v){
	if(!n) return;
	int x = g[n][m][v];
	print(lst[x][m][v], m - a[x], v - b[x]);
	printf("%d ", x);
}
int main(){
	int m = read(), v = read(), n = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read(), b[i] = read(), c[i] = read();
		for(int j = 0; j <= m; j++)
			for(int k = 0; k <= v; k++) {
				f[i][j][k] = f[i - 1][j][k];
				g[i][j][k] = g[i - 1][j][k];
				if(j >= a[i] && k >= b[i] && f[i - 1][j - a[i]][k - b[i]] + c[i] > f[i][j][k]) {
					f[i][j][k] = f[i - 1][j - a[i]][k - b[i]] + c[i];
					lst[i][j][k] = g[i - 1][j - a[i]][k - b[i]];
					g[i][j][k] = i;
				}
			}
	}
	printf("%d\n", f[n][m][v]);
	print(n, m, v);
}
