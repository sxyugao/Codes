#include <queue>
#include <cstdio>
#include <cstring>
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
const int MAXN = 1e4 + 5;
const int MAXM = 1e5 + 5;
int nedge = 1, head[MAXN];
struct Edge {
	int to, nxt, w;
} edge[MAXM << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
struct Pre {
	int v, id;
} pre[MAXN];
bool vis[MAXN];
int n, m, s, t;
bool bfs(){
	queue<int>q;
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	vis[s] = 1;
	q.push(s);
	while(!q.empty()) {
		int x = q.front(); q.pop();
		for(int i = head[x]; i; i = edge[i].nxt) {
			if(!edge[i].w) continue;
			int y = edge[i].to;
			if(vis[y]) continue;
			pre[y].v = x;
			pre[y].id = i;
			if(y == t) return 1;
			vis[y] = 1;
			q.push(y);
		}
	}
	return 0;
}
int main(){
	n = read(), m = read(), s = read(), t = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, 0);
	}
	int ans = 0;
	while(bfs()) {
		int Min = 1e9;
		for(int i = t; i != s; i = pre[i].v)
			Min = min(Min, edge[pre[i].id].w);
		for(int i = t; i != s; i = pre[i].v) {
			edge[pre[i].id].w -= Min;
			edge[pre[i].id ^ 1].w += Min;
		}
		ans += Min;
	}
	printf("%d", ans);
}
