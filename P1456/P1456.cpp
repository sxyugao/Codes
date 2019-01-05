#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 100005;
int n, m, x, y, heap[MAXN];
int f[MAXN], d[MAXN], lson[MAXN], rson[MAXN];
int Find(int x){
	return f[x] = f[x] == x ? x : Find(f[x]);
}
int merge(int x, int y){
	if(!x || !y) return max(x, y);
	if(heap[x] < heap[y] || (heap[x] == heap[y] && x > y)) swap(x, y);
	rson[x] = merge(y, rson[x]);
	f[rson[x]] = x;
	if(d[lson[x]] < d[rson[x]]) swap(lson[x], rson[x]);
	d[x] = d[rson[x]] + 1;
	return x;
}
int del(int x){
	heap[x] >>= 1;
	int rt = merge(lson[x], rson[x]);
	lson[x] = rson[x] = d[x] = 0;
	return merge(rt, x);
}
int main(){
	while(~scanf("%d", &n)) {
		memset(f, 0, sizeof(f));
		memset(d, 0, sizeof(d));
		memset(lson, 0, sizeof(lson));
		memset(rson, 0, sizeof(rson));
		for(int i = 1; i <= n; i++) {
			scanf("%d", heap + i);
			f[i] = i;
		}
		scanf("%d", &m);
		while(m--) {
			scanf("%d%d", &x, &y);
			x = Find(x), y = Find(y);
			if(x == y) {
				puts("-1");
				continue;
			}
			int L = del(x), R = del(y);
			int rt = merge(L, R);
			f[L] = f[R] = rt;
			printf("%d\n", heap[rt]);
		}
	}
}
