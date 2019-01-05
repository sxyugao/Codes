#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 2e5 + 5;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int n, k;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
int sum[10], f[MAXN][5], siz[MAXN];
long long ans, s[MAXN];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
void dfs(int x, int fa){
	f[x][0] = 1;
	siz[x] = 1;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa) continue;
		dfs(y, x);
		ans += s[x] * siz[y] + s[y] * siz[x];
		for(int j = k - 1; ~j; j--) sum[j] = sum[j + 1] + f[y][j];
		for(int j = 0; j < k; j++) ans += 1LL * f[x][j] * (sum[k - j] + sum[0]);
		for(int j = 0; j < k - 1; j++) f[x][j + 1] += f[y][j];
		s[x] += f[y][k - 1] + s[y];
		f[x][0] += f[y][k - 1];
		siz[x] += siz[y];
	}
}
int main(){
	n = read(), k = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	printf("%lld", ans);
}
