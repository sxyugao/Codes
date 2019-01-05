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
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN * 2];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int d[MAXN], f[MAXN], a[MAXN], b[MAXN], id[MAXN];
void dfs(int k, int fa){
	d[k] = d[fa] + 1;
	f[k] = fa;
	for(int i = head[k]; i; i = edge[i].nxt) {
		int u = edge[i].to;
		if(u == fa) continue;
		dfs(u, k);
	}
}
int main(){
	int n = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++)
		if(d[a[i]] < d[a[i - 1]]) return puts("No"), 0;
	for(int i = 1; i <= n; i++) id[a[i]] = i;
	for(int i = 1; i <= n; i++) b[i] = f[a[i]];
	int len = unique(b + 1, b + n + 1) - b - 1;
	for(int i = 1; i <= len; i++)
		if(id[b[i]] < id[b[i - 1]]) return puts("No"), 0;
	puts("Yes");
}
