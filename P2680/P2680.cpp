#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)) ? EOF : *p1++;
}
#define gc c = _gc()
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
	int to, nxt, w;
} edge[MAXN << 1];
inline void add(const int &x, const int &y, const int &z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int dis[MAXN], fa[MAXN], w[MAXN], siz[MAXN], son[MAXN];
void dfs1(int x, int f, int p){
	fa[x] = f;
	w[x] = p;
	siz[x] = 1;
	dis[x] = dis[f] + p;
	int Max = 0;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		dfs1(y, x, edge[i].w);
		if(siz[y] > Max) son[x] = y, Max = siz[y];
		siz[x] += siz[y];
	}
}
int d[MAXN], top[MAXN];
void dfs2(int x, int topf){
	d[x] = d[fa[x]] + 1;
	top[x] = topf;
	if(!son[x]) return;
	dfs2(son[x], topf);
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}
inline int LCA(int x, int y){
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		x = fa[top[x]];
	}
	return d[x] < d[y] ? x : y;
}
struct Ask {
	int x, y, lca, len;
} l[MAXN];
int n, m, a[MAXN];
void dfs(int x){
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa[x]) continue;
		dfs(y);
		a[x] += a[y];
	}
}
inline bool check(const int &Ans){
	memset(a, 0, sizeof(a));
	register int cnt = 0, Max = 0;
	for(register int i = 1; i <= m; i++) {
		if(l[i].len > Ans) {
			a[l[i].x]++; a[l[i].y]++;
			a[l[i].lca] -= 2;
			cnt++;
			Max = max(Max, l[i].len - Ans);
		}
	}
	dfs(1);
	for(register int i = 1; i <= n; i++)
		if(a[i] >= cnt && w[i] >= Max) return 1;
	return 0;
}
int main(){
	n = read(), m = read();
	for(register int i = 1; i < n; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z);
	}
	dfs1(1, 0, 0);
	dfs2(1, 1);
	for(register int i = 1; i <= m; i++) {
		l[i].x = read(), l[i].y = read();
		l[i].lca = LCA(l[i].x, l[i].y);
		l[i].len = dis[l[i].x] + dis[l[i].y] - 2 * dis[l[i].lca];
	}
	register int l = 0, r = 1e9, ans;
	while(l <= r) {
		register int mid = (l + r) >> 1;
		if(check(mid)) r = mid - 1, ans = mid;
		else l = mid + 1;
	}
	printf("%d", ans);
}
