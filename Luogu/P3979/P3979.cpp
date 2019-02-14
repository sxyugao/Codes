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
const int INF = 0x7fffffff;
const int MAXN = 100005;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int fa[MAXN], d[MAXN], siz[MAXN], son[MAXN], p[MAXN][25];
void dfs1(int x, int f){
	fa[x] = f;
	d[x] = d[f] + 1;
	siz[x] = 1;
	p[x][0] = fa[x];
	for(int i = 1; (1 << i) <= d[x]; i++)
		p[x][i] = p[p[x][i - 1]][i - 1];
	int Max = 0;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		dfs1(y, x);
		if(siz[y] > Max) Max = siz[y], son[x] = y;
		siz[x] += siz[y];
	}
}
int cnt, id[MAXN], a[MAXN], w[MAXN], top[MAXN];
void dfs2(int x, int topf){
	id[x] = ++cnt;
	a[cnt] = w[x];
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
struct Segtree {
	int l, r, min, lazy;
} tree[MAXN << 2];
void pushup(int k){
	tree[k].min = min(tree[k << 1].min, tree[k << 1 | 1].min);
}
void pushdown(int k){
	if(tree[k].lazy == -1) return;
	tree[k << 1].min = tree[k].lazy;
	tree[k << 1 | 1].min = tree[k].lazy;
	tree[k << 1].lazy = tree[k].lazy;
	tree[k << 1 | 1].lazy = tree[k].lazy;
	tree[k].lazy = -1;
}
void build(int k, int l, int r){
	tree[k].l = l; tree[k].r = r;
	tree[k].lazy = -1;
	if(l == r) {
		tree[k].min = a[l];
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void upd(int k, int l, int r, int v){
	if(tree[k].l > r || tree[k].r < l) return;
	if(l <= tree[k].l && tree[k].r <= r) {
		tree[k].lazy = v;
		tree[k].min = v;
		return;
	}
	pushdown(k);
	upd(k << 1, l, r, v); upd(k << 1 | 1, l, r, v);
	pushup(k);
}
void upd(int x, int y, int v){
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		upd(1, id[top[x]], id[x], v);
		x = fa[top[x]];
	}
	if(d[x] > d[y]) swap(x, y);
	upd(1, id[x], id[y], v);
}
int query(int k, int l, int r){
	if(tree[k].l > r || tree[k].r < l) return INF;
	if(l <= tree[k].l && tree[k].r <= r) return tree[k].min;
	pushdown(k);
	return min(query(k << 1, l, r), query(k << 1 | 1, l, r));
}
int n, m, root;
int Find(int tar, int x){
	for(int i = 20; i >= 0; i--)
		if(d[p[x][i]] > d[tar]) x = p[x][i];
	return x;
}
int query(int x){
	if(x == root) return query(1, id[1], id[1] + siz[1] - 1);
	int lca = LCA(root, x);
	if(lca != x) return query(1, id[x], id[x] + siz[x] - 1);
	int s = Find(x, root);
	return min(query(1, 1, id[s] - 1), query(1, id[s] + siz[s], n));
}
int main(){
	n = read(), m = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	for(int i = 1; i <= n; i++) w[i] = read();
	root = read();
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	while(m--) {
		int opt = read();
		if(opt == 1) root = read();
		if(opt == 2) {
			int x = read(), y = read();
			upd(x, y, read());
		}
		if(opt == 3) printf("%d\n", query(read()));
	}
}
