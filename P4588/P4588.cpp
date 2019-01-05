#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read() {
	int x = 0, f = 1; char gc;
	for (; !isdigit(c); gc) if (c == '-') f = -1;
	for (; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 1e5 + 5;
int n, P;
struct Query {
	int opt, x;
	void input(){
		opt = read();
		x = read();
	}
} q[MAXN];
struct Segtree {
	int l, r, x;
} tree[MAXN << 2];
#define lson k << 1
#define rson k << 1 | 1
void pushup(int k){
	tree[k].x = 1LL * tree[lson].x * tree[rson].x % P;
}
void build(int k, int l, int r){
	tree[k].l = l, tree[k].r = r;
	if(l == r) {
		tree[k].x = q[l].opt == 1 ? q[l].x : 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(lson, l, mid);
	build(rson, mid + 1, r);
	pushup(k);
}
void modify(int k, int l, int r){
	if(tree[k].l > r || tree[k].r < l) return;
	if(l <= tree[k].l && tree[k].r <= r) {
		tree[k].x = 1;
		return;
	}
	modify(lson, l, r);
	modify(rson, l, r);
	pushup(k);
}
int query(int k, int l, int r){
	if(tree[k].l > r || tree[k].r < l) return 1;
	if(l <= tree[k].l && tree[k].r <= r) return tree[k].x;
	return 1LL * query(lson, l, r) * query(rson, l, r) % P;
}
void work(){
	n = read(), P = read();
	for(int i = 1; i <= n; i++) q[i].input();
	build(1, 1, n);
	for(int i = 1; i <= n; i++) {
		if(q[i].opt == 2) modify(1, q[i].x, q[i].x);
		printf("%d\n", query(1, 1, i));
	}
}
int main() {
	for (int T = read(); T; T--) work();
}
