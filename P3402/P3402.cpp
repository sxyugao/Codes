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
const int MAXM = 2e5 + 5;
const int MAXN = 1e5 + 5;
int n, m;
int tot, T[MAXM], fa[MAXN * 30], d[MAXN * 30];
struct Segtree {
	int l, r;
} tree[MAXN * 30];
#define lson tree[rt].l
#define rson tree[rt].r
void build(int &rt, int l, int r){
	rt = ++tot;
	if(l == r) return (void)(fa[rt] = l);
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
}
void upd(int &rt, int lst, int l, int r, int p, int f){
	rt = ++tot;
	if(l == r) {
		fa[rt] = f;
		d[rt] = d[lst];
		return;
	}
	lson = tree[lst].l, rson = tree[lst].r;
	int mid = (l + r) >> 1;
	if(p <= mid) upd(lson, tree[lst].l, l, mid, p, f);
	else upd(rson, tree[lst].r, mid + 1, r, p, f);
}
int query(int rt, int l, int r, int p){
	if(l == r) return rt;
	int mid = (l + r) >> 1;
	if(p <= mid) return query(lson, l, mid, p);
	else return query(rson, mid + 1, r, p);
}
void add(int rt, int l, int r, int p){
	if(l == r) return (void)(++d[rt]);
	int mid = (l + r) >> 1;
	if(p <= mid) add(lson, l, mid, p);
	else add(rson, mid + 1, r, p);
}
int Find(int rt, int x){
	int f = query(rt, 1, n, x);
	if(x == fa[f]) return f;
	return Find(rt, fa[f]);
}
#undef lson
#undef rson
int main(){
	n = read(), m = read();
	build(T[0], 1, n);
	for(int i = 1; i <= m; i++) {
		int opt = read();
		if(opt == 1) {
			T[i] = T[i - 1];
			int x = Find(T[i], read()), y = Find(T[i], read());
			if(x == y) continue;
			if(d[x] > d[y]) swap(x, y);
			upd(T[i], T[i - 1], 1, n, fa[x], fa[y]);
			if(d[x] == d[y]) add(T[i], 1, n, fa[y]);
		}
		if(opt == 2) T[i] = T[read()];
		if(opt == 3) {
			T[i] = T[i - 1];
			int x = Find(T[i], read()), y = Find(T[i], read());
			putchar('0' + (x == y)); puts("");
		}
	}
}
