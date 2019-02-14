#include <cstdio>
#include <iostream>
using namespace std;
int x[4500010], y[4500010];
bool vis[2010][2010], cannot[2010][2010][4];
int main(){
	int n, ans = 0;
	int dx[] = {0, 1, 0, -1};
	int dy[] = {1, 0, -1, 0};
	scanf("%d", &n);
	while(n--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		x1 += 1005; y1 += 1005; x2 += 1005; y2 += 1005;
		if(y1 > y2) y1 ^= y2, y2 ^= y1, y1 ^= y2;
		if(x1 > x2) x1 ^= x2, x2 ^= x1, x1 ^= x2;
		if(x1 == x2) {
			for(int i = y1; i < y2; i++) {
				cannot[x1][i][3] = 1;
				cannot[x1 - 1][i][1] = 1;
			}
		}else{
			for(int i = x1; i < x2; i++) {
				cannot[i][y1][2] = 1;
				cannot[i][y1 - 1][0] = 1;
			}
		}
	}
	int l = 0, r = 1;
	x[1] = y[1] = 1;
	vis[1][1] = 1;
	while(l < r) {
		l++;
		for(int i = 0; i < 4; i++) {
			int tx = x[l] + dx[i];
			int ty = y[l] + dy[i];
			if(tx < 1 || tx > 2005 || ty < 1 || ty > 2005) continue;
			if(vis[tx][ty] || cannot[x[l]][y[l]][i]) continue;
			x[++r] = tx; y[r] = ty;
			vis[tx][ty] = 1;
		}
	}
	for(int i = 1; i <= 2005; i++)
		for(int j = 1; j <= 2005; j++) {
			if(vis[i][j]) continue;
			ans++;
			l = 0, r = 1;
			x[1] = i; y[1] = j;
			while(l < r) {
				l++;
				for(int k = 0; k < 4; k++) {
					int tx = x[l] + dx[k];
					int ty = y[l] + dy[k];
					if(tx < 1 || tx > 2005 || ty < 1 || ty > 2005) continue;
					if(vis[tx][ty]) continue;
					x[++r] = tx; y[r] = ty;
					vis[tx][ty] = 1;
				}
			}
		}
	printf("%d", ans);
}
