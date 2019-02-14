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
const int MAXN = 1e5 + 5;
int nedge, head[MAXN];
struct Edge {
	int to, w, nxt;
} edge[MAXN << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
long long f[MAXN];
long long dfs(int x, int fa, long long dis){
	long long sum = 0;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa) continue;
		sum += dfs(y, x, edge[i].w);
	}
	if(sum) f[x] = sum; else f[x] = 1e18;
	return f[x] = min(f[x], dis);
}
int main(){
	int n = read(), rt = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z);
	}
	printf("%lld", dfs(rt, 0, 1e18));
}
