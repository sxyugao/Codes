#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 1e5 + 5;
const int MAXM = 1e6 + 5;
int nedge, head[MAXN];
struct Edge {
	int to, w, nxt;
} edge[MAXM << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int num, h[MAXN], f[MAXN];
int Find(int x){
	return f[x] = f[x] == x ? x : Find(f[x]);
}
void dfs(int x){
	if(f[x]) return;
	f[x] = 1;
	num++;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		dfs(y);
	}
}
int cnt;
struct E {
	int x, y, z;
	bool operator<(const E &b) const {
		if(h[y] != h[b.y]) return h[y] > h[b.y];
		return z < b.z;
	}
} e[MAXM << 1];
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) h[i] = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read();
		if(h[x] >= h[y]) add(x, y, z);
		if(h[x] <= h[y]) add(y, x, z);
	}
	dfs(1);
	for(int x = 1; x <= n; x++) {
		if(!f[x]) continue;
		for(int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if(!f[y]) continue;
			e[++cnt].x = x;
			e[cnt].y = y;
			e[cnt].z = edge[i].w;
		}
	}
	sort(e + 1, e + cnt + 1);
	for(int i = 1; i <= n; i++) f[i] = i;
	long long ans = 0;
	for(int i = 1, tot = 0; i <= cnt && num > tot; i++) {
		int x = Find(e[i].x), y = Find(e[i].y);
		if(x == y) continue;
		f[x] = y;
		ans += e[i].z;
		tot++;
	}
	printf("%d %lld", num, ans);
}
