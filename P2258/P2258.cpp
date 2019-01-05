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
int Abs(int x){
	return x < 0 ? -x : x;
}
int n, m, r, c, ans;
int use[20], f[20][20], a[20][20];
void dp(){
	static int w[20], v[20][20];
	memset(v, 0, sizeof v);
	memset(w, 0, sizeof w);
	memset(f, 0x3f, sizeof f);
	for(int i = 1; i <= m; i++)
		for(int j = 1; j < r; j++)
			w[i] += Abs(a[use[j]][i] - a[use[j + 1]][i]);
	for(int i = 1; i <= m; i++)
		for(int j = i + 1; j <= m; j++)
			for(int k = 1; k <= r; k++)
				v[i][j] += Abs(a[use[k]][i] - a[use[k]][j]);
	f[0][0] = 0;
	for(int i = 1; i <= c; i++)
		for(int j = i; j <= m; j++)
			for(int k = 0; k < j; k++)
				f[i][j] = min(f[i][j], f[i - 1][k] + w[j] + v[k][j]);
	for(int i = c; i <= m; i++) ans = min(ans, f[c][i]);
}
void dfs(int x, int pre){
	if(x > r) return dp();
	for(int i = pre + 1; n - i >= r - x; i++) {
		use[x] = i;
		dfs(x + 1, i);
	}
}
int main(){
	n = read(), m = read(), r = read(), c = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = read();
	ans = 1e9;
	dfs(1, 0);
	printf("%d", ans);
}
