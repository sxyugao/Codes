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
bool a[2505][2505];
int f[2505][2505], g[2505][2505], L[2505][2505], R[2505][2505], D[2505][2505];
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = read();
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++)
			if(a[i][j]) L[i][j] = 0;
			else L[i][j] = L[i][j - 1] + 1;
		for(int j = m; j >= 1; j--)
			if(a[i][j]) R[i][j] = 0;
			else R[i][j] = R[i][j + 1] + 1;
		for(int j = 1; j <= m; j++)
			if(a[i][j]) D[i][j] = 0;
			else D[i][j] = D[i - 1][j] + 1;
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j]) {
				f[i][j] = min(f[i - 1][j - 1], min(L[i][j - 1], D[i - 1][j])) + 1;
				g[i][j] = min(g[i - 1][j + 1], min(R[i][j + 1], D[i - 1][j])) + 1;
				ans = max(ans, max(f[i][j], g[i][j]));
			}
	printf("%d", ans);
}
