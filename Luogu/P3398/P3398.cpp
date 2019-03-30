#include <cstdio>
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
const int MAXN = 1e5 + 5;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int dep[MAXN], fa[MAXN][25];
void dfs(int x, int f){
	dep[x] = dep[f] + 1;
	fa[x][0] = f;
	for(int i = 1; (1 << i) <= dep[x]; i++)
		fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		dfs(y, x);
	}
}
int lca(int x, int y){
	if(dep[x] < dep[y]) swap(x, y);
	for(int i = 20; ~i; i--)
		if(dep[fa[x][i]] >= dep[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; i--)
		if(fa[x][i] ^ fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
int main(){
	int n = read(), q = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
	dfs(1, 0);
	while(q--) {
		int a = read(), b = read(), c = read(), d = read();
		int x = lca(a, b), y = lca(c, d);
		if(dep[x] < dep[y]) {
			swap(x, y);
			swap(a, c);
			swap(b, d);
		}
		puts(lca(x, c) == x || lca(x, d) == x ? "Y" : "N");
	}
}
