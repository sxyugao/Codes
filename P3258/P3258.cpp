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
const int MAXN = 300005;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int w[MAXN], a[MAXN];
int d[MAXN], fa[MAXN], son[MAXN], siz[MAXN];
void dfs1(int x, int f){
	fa[x] = f;
	d[x] = d[f] + 1;
	siz[x] = 1;
	int Max = 0;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		dfs1(y, x);
		if(Max < siz[y]) son[x] = y, Max = siz[y];
		siz[x] += siz[y];
	}
}
int top[MAXN];
void dfs2(int x, int topf){
	top[x] = topf;
	if(!son[x]) return;
	dfs2(son[x], topf);
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}
int LCA(int x, int y){
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return d[x] < d[y] ? x : y;
}
void inc(int x, int y){
	a[x]++; a[y]++;
	int lca = LCA(x, y);
	a[lca]--; a[fa[lca]]--;
}
void dec(int x, int y){
	a[x]--; a[y]--;
	int lca = LCA(x, y);
	a[lca]++; a[fa[lca]]++;
}
void dfs(int x, int fa){
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa) continue;
		dfs(y, x);
		a[x] += a[y];
	}
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) w[i] = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	for(int i = 1; i < n; i++) inc(w[i], w[i + 1]);
	for(int i = 2; i <= n; i++) dec(w[i], w[i]);
	dfs(1, 0);
	for(int i = 1; i <= n; i++) printf("%d\n", a[i]);
}
