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
int nedge, head[105], h[105], in[105];
struct Edge {
	int to, nxt;
} edge[205], e[205];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
void Add(int x, int y){
	e[++nedge].to = y;
	e[nedge].nxt = h[x];
	h[x] = nedge;
	in[y]++;
}
int n, m, ww[105], vv[105];
bool vis[105];
int cnt, dfn[105], low[105];
int top, stack[105];
int scc, w[105], v[105], col[105];
void dfs(int x){
	dfn[x] = low[x] = ++cnt; vis[x] = 1; stack[++top] = x;
	int y;
	for(int i = head[x]; i; i = edge[i].nxt) {
		y = edge[i].to;
		if(!dfn[y]) {
			dfs(y);
			low[x] = min(low[x], low[y]);
		}else if(vis[y]) low[x] = min(low[x], dfn[y]);
	}
	if(dfn[x] == low[x]) {
		scc++;
		do {
			y = stack[top--];
			vis[y] = 0;
			v[scc] += vv[y];
			w[scc] += ww[y];
			col[y] = scc;
		} while(x != y);
	}
}
int f[105][505];
void dfs(int k, int fa){
	for(int i = h[k]; i; i = e[i].nxt) {
		int u = e[i].to;
		dfs(u, k);
	}
	for(int i = m; i >= w[k]; i--)
		f[k][i] = f[k][i - w[k]] + v[k];
	for(int i = 0; i < w[k]; i++) f[k][i] = 0;
	for(int i = m; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			f[fa][i] = max(f[fa][i], f[fa][i - j] + f[k][j]);
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) ww[i] = read();
	for(int i = 1; i <= n; i++) vv[i] = read();
	for(int i = 1; i <= n; i++) add(read(), i);
	for(int i = 0; i <= n; i++)
		if(!dfn[i]) dfs(i);
	nedge = 0;
	for(int i = 1; i <= n; i++)
		for(int k = head[i]; k; k = edge[k].nxt) {
			int j = edge[k].to;
			if(col[i] != col[j]) Add(col[i], col[j]);
		}
	for(int i = 1; i <= scc; i++)
		if(!in[i] && col[0] != i) Add(col[0], i);
	dfs(col[0], 0);
	printf("%d", f[0][m]);
}
