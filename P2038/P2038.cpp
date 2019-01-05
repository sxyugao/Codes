#include <cstdio>
#include <iostream>
using namespace std;
int d, n, a[150][150];
int main(){
	scanf("%d%d", &d, &n);
	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		scanf("%d", &a[x][y]);
	}
	int ans = 0;
	for(int i = 0; i <= 128; i++)
		for(int j = 0; j <= 128; j++) {
			int sx = max(0, i - d);
			int sy = max(0, j - d);
			int ex = min(128, i + d);
			int ey = min(128, j + d);
			int tmp = 0;
			for(int p = sx; p <= ex; p++)
				for(int q = sy; q <= ey; q++)
					tmp += a[p][q];
			ans = max(ans, tmp);
		}
	int cnt = 0;
	for(int i = 0; i <= 128; i++)
		for(int j = 0; j <= 128; j++) {
			int sx = max(0, i - d);
			int sy = max(0, j - d);
			int ex = min(128, i + d);
			int ey = min(128, j + d);
			int tmp = 0;
			for(int p = sx; p <= ex; p++)
				for(int q = sy; q <= ey; q++)
					tmp += a[p][q];
			cnt += (tmp == ans);
		}
	printf("%d %d", cnt, ans);
}
