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
const int MAXN = 100005;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN * 2];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int d[MAXN], siz[MAXN], f[MAXN][25];
void dfs(int x, int fa){
	d[x] = d[fa] + 1;
	siz[x] = 1;
	f[x][0] = fa;
	for(int i = 1; (1 << i) <= d[x]; i++) f[x][i] = f[f[x][i - 1]][i - 1];
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa) continue;
		dfs(y, x);
		siz[x] += siz[y];
	}
}
int lca(int x, int y){
	for(int i = 20; ~i; i--)
		if(d[x] + (1 << i) <= d[y]) y = f[y][i];
	if(x == y) return x;
	for(int i = 20; ~i; i--)
		if(f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
	return f[x][0];
}
int main(){
	int n = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	for(int m = read(); m; m--) {
		int x = read(), y = read();
		if(x == y) {
			printf("%d\n", n);
			continue;
		}
		if(d[x] > d[y]) swap(x, y);
		if((d[y] - d[x]) & 1) {
			puts("0");
			continue;
		}
		int dis = d[lca(x, y)] + (d[y] - d[x]) / 2;
		if(d[x] != d[y]) {
			for(int i = 20; ~i; i--)
				if(d[y] - (1 << i) > dis) y = f[y][i];
			printf("%d\n", siz[f[y][0]] - siz[y]);
		}else{
			for(int i = 20; ~i; i--)
				if(d[y] - (1 << i) > dis) y = f[y][i];
			for(int i = 20; ~i; i--)
				if(d[x] - (1 << i) > dis) x = f[x][i];
			printf("%d\n", n - siz[y] - siz[x]);
		}
	}
}
