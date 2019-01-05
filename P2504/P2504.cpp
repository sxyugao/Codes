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
int sqr(int x){
	return x * x;
}
int nedge, d[505], x[1005], y[1005];
struct Edge {
	int x, y, z;
	bool operator<(const Edge &b) const {
		return z < b.z;
	}
} edge[1000005];
int f[1005];
int Find(int k){
	return f[k] == k ? k : f[k] = Find(f[k]);
}
int main(){
	int m = read();
	for(int i = 1; i <= m; i++) d[i] = read();
	int n = read();
	for(int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			edge[++nedge].x = i;
			edge[nedge].y = j;
			edge[nedge].z = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
		}
	sort(edge + 1, edge + nedge + 1);
	int need = 0;
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= nedge && n > 1; i++) {
		int a = Find(edge[i].x), b = Find(edge[i].y);
		if(a != b) {
			n--;
			f[b] = a;
			need = edge[i].z;
		}
	}
	int ans = 0;
	for(int i = 1; i <= m; i++)
		if(sqr(d[i]) >= need) ans++;
	printf("%d", ans);
}
