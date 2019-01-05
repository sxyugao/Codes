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
const int MAXN = 3e5 + 5;
int a[MAXN], b[MAXN], c[MAXN * 25];
int tot, T[MAXN], L[MAXN * 25], R[MAXN * 25];
#define mid ((l + r) / 2)
int build(int l, int r){
	int rt = ++tot;
	if(l < r) {
		L[rt] = build(l, mid);
		R[rt] = build(mid + 1, r);
	}
	return rt;
}
int upd(int pre, int l, int r, int x){
	int rt = ++tot;
	L[rt] = L[pre], R[rt] = R[pre];
	c[rt] = c[pre] + 1;
	if(l < r) {
		if(x <= mid) L[rt] = upd(L[pre], l, mid, x);
		else R[rt] = upd(R[pre], mid + 1, r, x);
	}
	return rt;
}
int query(int x, int y, int l, int r, int k){
	if(l >= r) return l;
	int tmp = c[L[y]] - c[L[x]];
	if(tmp >= k) return query(L[x], L[y], l, mid, k);
	else return query(R[x], R[y], mid + 1, r, k - tmp);
}
#undef mid
int main(){
	int n = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = b[i] = read();
	sort(b + 1, b + n + 1);
	int m = unique(b + 1, b + n + 1) - b - 1;
	T[0] = build(1, m);
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + m + 1, a[i]) - b;
		T[i] = upd(T[i - 1], 1, m, a[i]);
	}
	while(q--) {
		int x = read(), y = read(), z = read();
		printf("%d\n", b[query(T[x - 1], T[y], 1, m, z)]);
	}
}
