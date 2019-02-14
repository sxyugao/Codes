#include <cstdio>
#include <iostream>
using namespace std;
const int P = 1e9 + 7;
int f[2005][2005];
void add(int &x, int y){
	x = x + y >= P ? x + y - P : x + y;
}
int main(){
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++) f[1][i] = 1;
	for(int i = 2; i <= n; i++) {
		int sum = 0;
		f[i][1] = 1;
		for(int j = 2; j <= m; j++) {
			add(sum, f[i - 1][j]);
			add(f[i][j], f[i][j - 1] + sum);
		}
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= m; j++) {
			int U = f[i][j] - f[i - 1][j] + P;
			int D = f[n - i + 1][j];
			add(ans, 1LL * U * D % P * (m - j + 1) % P);
		}
	printf("%d", ans);
}
