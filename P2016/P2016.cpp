#include <queue>
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
const int MAXN = 1500;
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int f[MAXN], in[MAXN];
void dfs(int k, int fa){
	f[k] = fa;
	for(int i = head[k]; i; i = edge[i].nxt) {
		int u = edge[i].to;
		if(u == fa) continue;
		dfs(u, k);
		in[k]++;
	}
}
int vis[MAXN];
queue<int>q;
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) {
		int x = read() + 1;
		for(int num = read(); num; num--) {
			int y = read() + 1;
			add(x, y), add(y, x);
		}
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++)
		if(!in[i]) q.push(i);
	while(q.front() != 1) {
		int now = q.front(); q.pop();
		if(!vis[now]) vis[f[now]] = 1;
		in[f[now]]--;
		if(!in[f[now]]) q.push(f[now]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(vis[i]) ans++;
	printf("%d", ans);
}
