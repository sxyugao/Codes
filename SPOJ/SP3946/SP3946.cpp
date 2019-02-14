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
const int MAXN = 200005;
int tot, a[MAXN], b[MAXN];
int T[MAXN], sum[MAXN * 20], L[MAXN * 20], R[MAXN * 20];
int build(int l, int r){
	int rt = ++tot;
	int mid = (l + r) >> 1;
	if(l < r) {
		L[rt] = build(l, mid);
		R[rt] = build(mid + 1, r);
	}
	return rt;
}
int update(int pre, int l, int r, int x){
	int rt = ++tot;
	L[rt] = L[pre]; R[rt] = R[pre];
	sum[rt] = sum[pre] + 1;
	int mid = (l + r) >> 1;
	if(l < r) {
		if(x <= mid) L[rt] = update(L[pre], l, mid, x);
		else R[rt] = update(R[pre], mid + 1, r, x);
	}
	return rt;
}
int query(int u, int v, int l, int r, int k){
	if(l >= r) return l;
	int x = sum[L[v]] - sum[L[u]];
	int mid = (l + r) >> 1;
	if(x >= k) return query(L[u], L[v], l, mid, k);
	else return query(R[u], R[v], mid + 1, r, k - x);
}
int main(){
	int n = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = b[i] = read();
	sort(b + 1, b + 1 + n);
	int m = unique(b + 1, b + 1 + n) - b - 1;
	T[0] = build(1, m);
	for(int i = 1; i <= n; i++) {
		a[i] = lower_bound(b + 1, b + 1 + m, a[i]) - b;
		T[i] = update(T[i - 1], 1, m, a[i]);
	}
	while(q--) {
		int x = read(), y = read(), z = read();
		printf("%d\n", b[query(T[x - 1], T[y], 1, m, z)]);
	}
}
