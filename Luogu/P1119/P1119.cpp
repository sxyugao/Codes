#include <cstdio>
#include <cstring>
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
const int INF = 0x3f3f3f3f;
int t[205], a[200][200];
int main(){
	int n = read(), m = read();
	for(int i = 0; i < n; i++) t[i] = read();
	t[n] = INF;
	memset(a, 0x3f, sizeof(a));
	for(int i = 0; i < n; i++) a[i][i] = 0;
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		a[x][y] = a[y][x] = read();
	}
	int k = 0;
	for(int q = read(); q; q--) {
		int X = read(), Y = read(), T = read();
		while(t[k] <= T && k < n) {
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			k++;
		}
		if(t[X] > T || t[Y] > T || a[X][Y] == INF) puts("-1");
		else printf("%d\n", a[X][Y]);
	}
}
