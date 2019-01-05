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
int f[105][105];
int main(){
	int n = read();
	memset(f, 0x3f, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][i] = 0;
	for(int m = read(); m; m--) {
		int opt = read(), x = read(), y = read();
		if(opt) {
			f[x][y] = f[y][x] = min(read(), f[x][y]);
			for(int i = 1; i <= n; i++)
				for(int j = 1; j <= n; j++)
					f[i][j] = min(f[i][j], min(f[i][x] + f[y][j], f[i][y] + f[x][j]) + f[x][y]);
		}else printf("%d\n", f[x][y] == INF ? -1 : f[x][y]);
	}
}
