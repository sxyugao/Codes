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
const int MAXN = 1005;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int fa[MAXN][25], d[MAXN], deg[MAXN];
void dfs(int x, int f){
	fa[x][0] = f;
	d[x] = d[f] + 1;
	for(int i = 1; (1 << i) <= d[x]; i++) fa[x][i] = fa[fa[x][i - 1]][i - 1];
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		dfs(y, x);
	}
}
int lca(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	for(int i = 20; ~i; i--)
		if(d[fa[x][i]] >= d[y]) x = fa[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; i--)
		if(fa[x][i] ^ fa[y][i])
			x = fa[x][i], y = fa[y][i];
	return fa[x][0];
}
void init(){
	nedge = 0;
	memset(fa, 0, sizeof(fa));
	memset(deg, 0, sizeof(deg));
	memset(head, 0, sizeof(head));
}
int main(){
	for(int T = 1, Case = read(); T <= Case; T++) {
		printf("Case %d:\n", T);
		int n = read();
		init();
		for(int i = 1; i <= n; i++) {
			for(int num = read(); num; num--) {
				int x = read();
				add(i, x); add(x, i);
				deg[x]++;
			}
		}
		int rt = 0;
		for(int i = 1; i <= n; i++)
			if(!deg[i]) rt = i;
		dfs(rt, 0);
		for(int q = read(); q; q--) {
			int x = read(), y = read();
			printf("%d\n", lca(x, y));
		}
	}
}
