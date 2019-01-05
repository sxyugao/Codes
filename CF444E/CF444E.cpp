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
const int MAXN = 1e5 + 5;
struct Edge {
	int x, y, z;
	bool operator<(const Edge &b) const {
		return z < b.z;
	}
	void input(){
		x = read(), y = read(), z = read();
	}
} edge[MAXN];
int siz[MAXN], a[MAXN], f[MAXN];
int Find(int x){
	return f[x] == x ? x : Find(f[x]);
}
int main(){
	int n = read();
	for(int i = 1; i < n; i++) edge[i].input();
	sort(edge + 1, edge + n);
	int sum = 0;
	for(int i = 1; i <= n; i++) {
		f[i] = i;
		siz[i] = 1;
		sum += a[i] = read();
	}
	int ans = 0;
	for(int i = 1; i < n; i++) {
		ans = edge[i].z;
		int x = Find(edge[i].x), y = Find(edge[i].y);
		if(x != y) {
			a[x] += a[y];
			siz[x] += siz[y];
			f[y] = x;
			if(siz[x] > sum - a[x]) break;
		}
	}
	printf("%d", ans);
}
