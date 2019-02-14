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
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int fa[MAXN], d[MAXN], siz[MAXN], son[MAXN];
void dfs1(int x, int f){
	fa[x] = f;
	d[x] = d[f] + 1;
	siz[x] = 1;
	int Max = 0;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		dfs1(y, x);
		if(siz[y] > Max) Max = siz[y], son[x] = y;
		siz[x] += siz[y];
	}
}
int cnt, id[MAXN], top[MAXN];
void dfs2(int x, int topf){
	top[x] = topf;
	id[x] = ++cnt;
	if(!son[x]) return;
	dfs2(son[x], topf);
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa[x] || y == son[x]) continue;
		dfs2(y, y);
	}
}
struct Segtree {
	int l, r, a[2], lazy;
} tree[MAXN << 2];
void pushup(int k){
	tree[k].a[0] = tree[k << 1].a[0] + tree[k << 1 | 1].a[0];
	tree[k].a[1] = tree[k << 1].a[1] + tree[k << 1 | 1].a[1];
}
void pushdown(int k){
	if(tree[k].lazy == -1) return;
	bool f = tree[k].lazy;
	tree[k << 1].lazy = tree[k << 1 | 1].lazy = f;
	tree[k << 1].a[f] = tree[k << 1].r - tree[k << 1].l + 1;
	tree[k << 1].a[f ^ 1] = 0;
	tree[k << 1 | 1].a[f] = tree[k << 1 | 1].r - tree[k << 1 | 1].l + 1;
	tree[k << 1 | 1].a[f ^ 1] = 0;
	tree[k].lazy = -1;
}
void build(int k, int l, int r){
	tree[k].l = l; tree[k].r = r;
	tree[k].lazy = -1;
	if(l == r) {
		tree[k].a[0] = 1;
		tree[k].a[1] = 0;
		return;
	}
	int mid = (l + r) >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
	pushup(k);
}
void upd(int k, int l, int r, bool v){
	if(tree[k].r<l || tree[k].l>r) return;
	if(l <= tree[k].l && tree[k].r <= r) {
		tree[k].a[v] = tree[k].r - tree[k].l + 1;
		tree[k].a[v ^ 1] = 0;
		tree[k].lazy = v;
		return;
	}
	pushdown(k);
	upd(k << 1, l, r, v); upd(k << 1 | 1, l, r, v);
	pushup(k);
}
void upd(int x, int y, bool v){
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		upd(1, id[top[x]], id[x], v);
		x = fa[top[x]];
	}
	if(d[x] > d[y]) swap(x, y);
	upd(1, id[x], id[y], v);
}
int query(int k, int l, int r, bool v){
	if(tree[k].r<l || tree[k].l>r) return 0;
	if(l <= tree[k].l && tree[k].r <= r) return tree[k].a[v];
	pushdown(k);
	return query(k << 1, l, r, v) + query(k << 1 | 1, l, r, v);
}
int query(int x, int y, bool v){
	int ans = 0;
	while(top[x] != top[y]) {
		if(d[top[x]] < d[top[y]]) swap(x, y);
		ans += query(1, id[top[x]], id[x], v);
		x = fa[top[x]];
	}
	if(d[x] > d[y]) swap(x, y);
	return ans + query(1, id[x], id[y], v);
}
char opt[10];
int main(){
	int n = read();
	for(int i = 2; i <= n; i++) {
		int x = read() + 1;
		add(i, x); add(x, i);
	}
	dfs1(1, 0);
	dfs2(1, 1);
	build(1, 1, n);
	for(int m = read(); m; m--) {
		scanf("%s", opt);
		int x = read() + 1;
		if(*opt == 'i') {
			printf("%d\n", d[x] - query(1, x, 1));
			upd(1, x, 1);
		}else{
			printf("%d\n", siz[x] - query(1, id[x], id[x] + siz[x] - 1, 0));
			upd(1, id[x], id[x] + siz[x] - 1, 0);
		}
	}
}
