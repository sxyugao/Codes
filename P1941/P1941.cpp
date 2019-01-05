#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int INF = 0x3f3f3f3f;
const int MAXN = 1e4 + 5;
const int MAXM = 1e3 + 5;
int x[MAXN], y[MAXN], low[MAXN], high[MAXN];
int f[MAXN][MAXM];
bool used[MAXN];
int main(){
	register int n = read(), m = read(), num = read();
	for(register int i = 0; i < n; i++) x[i] = read(), y[i] = read();
	for(register int i = 1; i <= n; i++) low[i] = 1, high[i] = m;
	for(register int i = 1; i <= num; i++) {
		register int p = read();
		low[p] = read() + 1, high[p] = read() - 1;
		used[p] = 1;
	}
	memset(f, 0x3f, sizeof(f));
	for(register int i = 1; i <= m; i++) f[0][i] = 0;
	for(register int i = 1; i <= n; i++) {
		for(register int j = 1; j < m; j++) {
			if(j >= x[i - 1]) {
				f[i][j] = min(f[i][j], f[i - 1][j - x[i - 1]] + 1);
				f[i][j] = min(f[i][j], f[i][j - x[i - 1]] + 1);
			}
			for(register int k = m - x[i - 1]; k <= m; k++) {
				f[i][m] = min(f[i][m], f[i - 1][k] + 1);
				f[i][m] = min(f[i][m], f[i][k] + 1);
			}
		}
		for(register int j = low[i]; j <= high[i]; j++)
			if(j + y[i - 1] <= m) f[i][j] = min(f[i][j], f[i - 1][j + y[i - 1]]);
		for(register int j = 1; j < low[i]; j++) f[i][j] = INF;
		for(register int j = high[i] + 1; j <= m; j++) f[i][j] = INF;
	}
	register int ans = num = 0;
	for(register int i = 1; i <= n; i++) {
		register int Min = INF;
		for(register int j = low[i]; j <= high[i]; j++) Min = min(Min, f[i][j]);
		if(Min == INF) {
			puts("0");
			printf("%d\n", num);
			return 0;
		}
		ans = Min;
		if(used[i]) num++;
	}
	puts("1");
	printf("%d\n", ans);
}
