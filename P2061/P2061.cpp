#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 40005;
struct Seg {
	int l, r, h;
	bool operator<(const Seg &b) const {
		return h < b.h;
	}
} a[MAXN];
int b[MAXN * 3];
struct Segtree {
	int l, r;
	long long max, lazy;
} tree[MAXN * 4];
void pushup(int k){
	tree[k].max = max(tree[k << 1].max, tree[k << 1 | 1].max);
}
void pushdown(int k){
	if(!tree[k].lazy) return;
	tree[k << 1].max = tree[k].lazy;
	tree[k << 1 | 1].max = tree[k].lazy;
	tree[k << 1].lazy = tree[k << 1 | 1].lazy = tree[k].lazy;
	tree[k].lazy = 0;
}
void build(int k, int l, int r){
	tree[k].l = l; tree[k].r = r;
	if(l == r) return;
	int mid = (l + r) >> 1;
	build(k << 1, l, mid); build(k << 1 | 1, mid + 1, r);
}
void upd(int k, int l, int r, long long v){
	if(tree[k].l > r || tree[k].r < l) return;
	if(l <= tree[k].l && tree[k].r <= r) {
		tree[k].lazy = v;
		tree[k].max = v;
		return;
	}
	pushdown(k);
	upd(k << 1, l, r, v); upd(k << 1 | 1, l, r, v);
	pushup(k);
}
long long query(int k, int l, int r){
	if(tree[k].l > r || tree[k].r < l) return -0x7fffffff;
	if(l <= tree[k].l && tree[k].r <= r) return tree[k].max;
	pushdown(k);
	return max(query(k << 1, l, r), query(k << 1 | 1, l, r));
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i].l = read(), a[i].r = read() - 1;
		a[i].h = read();
		b[++b[0]] = a[i].l; b[++b[0]] = a[i].r; b[++b[0]] = a[i].r + 1;
	}
	sort(a + 1, a + n + 1);
	sort(b + 1, b + b[0] + 1);
	int num = unique(b + 1, b + b[0] + 1) - b - 1;
	build(1, 1, num);
	for(int i = 1; i <= n; i++) {
		int l = lower_bound(b + 1, b + num + 1, a[i].l) - b;
		int r = lower_bound(b + 1, b + num + 1, a[i].r) - b;
		upd(1, l, r, a[i].h);
	}
	long long ans = 0;
	for(int i = 1; i < num; i++)
		ans += query(1, i, i) * (b[i + 1] - b[i]);
	printf("%lld", ans);
}
