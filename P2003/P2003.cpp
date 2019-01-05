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
const int INF = 0x7fffffff;
struct Seg {
	Seg(){
	}
	Seg(int L, int R, int H){
		l = L; r = R; h = H;
	}
	int l, r, h;
	bool operator<(const Seg &b) const {
		return h < b.h;
	}
} a[105];
int tree[40005], lazy[40005];
int query(int k, int L, int R, int pos){
	if(L == R) return tree[k];
	if(lazy[k]) {
		lazy[k << 1] = lazy[k << 1 | 1] = lazy[k];
		tree[k << 1] = tree[k << 1 | 1] = lazy[k];
		lazy[k] = 0;
	}
	int mid = (L + R) >> 1;
	int ans = -INF;
	if(mid >= pos) ans = max(ans, query(k << 1, L, mid, pos));
	if(mid < pos) ans = max(ans, query(k << 1 | 1, mid + 1, R, pos));
	return ans;
}
void upd(int k, int L, int R, int l, int r, int v){
	if(l <= L && R <= r) {
		tree[k] = v;
		lazy[k] = v;
		return;
	}
	if(lazy[k]) {
		lazy[k << 1] = lazy[k << 1 | 1] = lazy[k];
		tree[k << 1] = tree[k << 1 | 1] = lazy[k];
		lazy[k] = 0;
	}
	int mid = (L + R) >> 1;
	if(mid >= l) upd(k << 1, L, mid, l, r, v);
	if(mid < r) upd(k << 1 | 1, mid + 1, R, l, r, v);
	tree[k] = max(tree[k << 1], tree[k << 1 | 1]);
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) {
		int h = read(), l = read(), r = read();
		a[i] = Seg(l, r - 1, h);
	}
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans += a[i].h * 2 - query(1, 1, 10000, a[i].l) - query(1, 1, 10000, a[i].r);
		upd(1, 1, 10000, a[i].l, a[i].r, a[i].h);
	}
	printf("%d", ans);
}
