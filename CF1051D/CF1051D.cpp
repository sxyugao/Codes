#include <cstdio>
#include <iostream>
using namespace std;
int n, k, f[1005][2005][4];
void Add(int &x, int y){
	(x += y) %= 998244353;
}
int main(){
	scanf("%d%d", &n, &k);
	f[1][1][0] = f[1][2][1] = f[1][2][2] = f[1][1][3] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= k; j++) {
			for(int p = 0; p < 4; p++) Add(f[i][j][0], f[i - 1][j - (p == 3)][p]);
			for(int p = 0; p < 4; p++) Add(f[i][j][3], f[i - 1][j - (p == 0)][p]);
			for(int p = 0; p < 4; p++) Add(f[i][j][1], f[i - 1][j - 1 - (p == 2) + (p == 1)][p]);
			for(int p = 0; p < 4; p++) Add(f[i][j][2], f[i - 1][j - 1 - (p == 1) + (p == 2)][p]);
		}
	int ans = 0;
	for(int i = 0; i < 4; i++) Add(ans, f[n][k][i]);
	printf("%d", ans);
}
