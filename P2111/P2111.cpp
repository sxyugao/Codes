#include <cstdio>
#include <iostream>
using namespace std;
int n, a, q;
double f[2][10005];
int main(){
	scanf("%d%d%d", &n, &a, &q);
	char c = getchar();
	while(isspace(c)) c = getchar();
	f[0][0] = 1;
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j <= i; j++) f[i & 1][j] = 0;
		if(c == '1') f[i & 1][0] = f[(i - 1) & 1][0] * (1.0 - 1.0 * a / 100);
		else f[i & 1][0] = f[(i - 1) & 1][0] * 1.0 * a / 100;
		for(int j = 1; j <= i; j++)
			if(c == '1') {
				f[i & 1][j] += 1.0 * a / 100 * f[(i - 1) & 1][j - 1];
				f[i & 1][j] += (1.0 - 1.0 * a / 100) * f[(i - 1) & 1][j];
			}
			else{
				f[i & 1][j] += (1.0 - 1.0 * a / 100) * f[(i - 1) & 1][j - 1];
				f[i & 1][j] += 1.0 * a / 100 * f[(i - 1) & 1][j];
			}
		c = getchar();
	}
	double ans = 0;
	for(int i = q; i <= n; i++) ans += f[n & 1][i];
	printf("%.3lf", ans);
}
