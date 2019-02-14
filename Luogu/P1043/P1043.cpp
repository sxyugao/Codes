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
const int P = 10;
int n, m, a[105], s[55], sum[55][55];
int ans1, ans2;
int Dp(){
	static int f[55][10];
	memset(f, 0, sizeof(f));
	for(int i = 1; i <= n; i++) f[i][1] = sum[1][i];
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= m; j++)
			for(int k = 1; k < i; k++)
				f[i][j] = max(f[i][j], f[k][j - 1] * sum[k + 1][i]);
	return f[n][m];
}
int dp(){
	static int f[55][10];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = 1e8;
	for(int i = 1; i <= n; i++) f[i][1] = sum[1][i];
	for(int i = 1; i <= n; i++)
		for(int j = 2; j <= m; j++)
			for(int k = 1; k < i; k++)
				f[i][j] = min(f[i][j], f[k][j - 1] * sum[k + 1][i]);
	return f[n][m];
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = a[i + n] = read();
	ans1 = 1e9, ans2 = 0;
	for(int p = 0; p < n; p++) {
		for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[p + i];
		for(int i = 1; i <= n; i++)
			for(int j = i; j <= n; j++)
				sum[i][j] = ((s[j] - s[i - 1]) % P + P) % P;
		ans1 = min(ans1, dp());
		ans2 = max(ans2, Dp());
	}
	printf("%d\n%d", ans1, ans2);
}
