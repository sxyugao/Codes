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
const int MAXN = 1000005;
int heap[MAXN], lson[MAXN], rson[MAXN];
int d[MAXN], f[MAXN];
bool deleted[MAXN];
char opt[1];
int Find(int x){
	for(; f[x]; x = f[x]);
	return x;
}
int merge(int x, int y){
	if(!x || !y) return max(x, y);
	if(heap[x] > heap[y] || (heap[x] == heap[y] && x > y)) swap(x, y);
	rson[x] = merge(rson[x], y); f[rson[x]] = x;
	if(d[lson[x]] < d[rson[x]]) swap(lson[x], rson[x]);
	d[x] = d[rson[x]] + 1;
	return x;
}
void del(int x){
	if(deleted[x]) return (void)puts("0");
	x = Find(x);
	printf("%d\n", heap[x]);
	deleted[x] = 1;
	f[lson[x]] = f[rson[x]] = 0;
	merge(lson[x], rson[x]);
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) heap[i] = read();
	for(int m = read(); m; m--) {
		scanf("%s", opt);
		if(*opt == 'M') {
			int x = read(), y = read();
			if(deleted[x] || deleted[y]) continue;
			x = Find(x), y = Find(y);
			if(x == y) continue;
			merge(x, y);
		}else del(read());
	}
}
