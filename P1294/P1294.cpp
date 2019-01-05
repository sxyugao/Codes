#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int a[55][55], f[1 << 20][25];
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = a[y][x] = z;
	}
	memset(f, 0xc0, sizeof(f));
	for(int i = 1; i <= n; i++) f[1 << (i - 1)][i] = 0;
	int ans = 0;
	for(int k = 1; k < (1 << n); k++)
		for(int i = 1; i <= n; i++)
			if(k & (1 << (i - 1))) {
				for(int j = 1; j <= n; j++)
					if(a[i][j] && !(k & (1 << (j - 1)))) {
						f[k | (1 << (j - 1))][j] = max(f[k | 1 << (j - 1)][j], f[k][i] + a[i][j]);
						ans = max(f[k | (1 << (j - 1))][j], ans);
					}
			}
	printf("%d", ans);
}
