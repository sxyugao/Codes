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
const int MAXN = 10005;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
bool vis[MAXN];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
void dfs(int k, int r){
	vis[k] = 1;
	if(!r) return;
	for(int i = head[k]; i; i = edge[i].nxt) {
		int u = edge[i].to;
		dfs(u, r - 1);
	}
}
int d[MAXN];
void init(int k, int fa){
	d[k] = d[fa] + 1;
	for(int i = head[k]; i; i = edge[i].nxt) {
		int u = edge[i].to;
		if(u == fa) continue;
		init(u, k);
	}
}
int main(){
	int n = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y); add(y, x);
	}
	init(1, 0);
	int ans = 0;
	while(1) {
		int k = 0;
		for(int i = 1; i <= n; i++)
			if(!vis[i] && d[k] < d[i]) k = i;
		if(!k) break;
		dfs(k, 2);
		ans++;
	}
	printf("%d", ans);
}
