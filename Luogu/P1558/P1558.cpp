#include <cstdio>
#include <bitset>
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
struct Segtree {
	int l, r, lazy;
	bitset<30>state;
} tree[MAXN << 2];
void pushup(int k){
	tree[k].state = tree[k << 1].state | tree[k << 1 | 1].state;
}
void pushdown(int k){
	if(!tree[k].lazy) return;
	tree[k << 1].lazy = tree[k << 1 | 1].lazy = tree[k].lazy;
	tree[k << 1].state = tree[k << 1 | 1].state = tree[k].lazy;
	tree[k].lazy = 0;
}
void build(int k, int l, int r){
	tree[k].l = l; tree[k].r = r;
	tree[k].state = 1;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void upd(int k, int l, int r, int v){
	if(tree[k].l > r || tree[k].r < l) return;
	if(l <= tree[k].l && tree[k].r <= r) {
		tree[k].lazy = 1 << (v - 1);
		tree[k].state = 1 << (v - 1);
		return;
	}
	pushdown(k);
	upd(k << 1, l, r, v); upd(k << 1 | 1, l, r, v);
	pushup(k);
}
bitset<30> query(int k, int l, int r){
	if(tree[k].l > r || tree[k].r < l) return 0;
	if(l <= tree[k].l && tree[k].r <= r) return tree[k].state;
	pushdown(k);
	return query(k << 1, l, r) | query(k << 1 | 1, l, r);
}
char opt[1];
int main(){
	int n = read(), T = read();
	build(1, 1, n);
	for(int m = read(); m; m--) {
		scanf("%s", opt);
		int l = read(), r = read();
		if(l > r) swap(l, r);
		if(*opt == 'C') upd(1, l, r, read());
		else printf("%lld\n", query(1, l, r).count());
	}
}
