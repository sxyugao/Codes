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
const int MAXN = 5005;
const int MAXM = 5e4 + 5;
int nedge = 1, head[MAXN];
struct Edge {
	int cost, w, to, nxt;
} edge[MAXM << 1];
void add(int x, int y, int w, int cost){
	edge[++nedge].to = y;
	edge[nedge].w = w;
	edge[nedge].cost = cost;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
struct Pre {
	int v, id;
} pre[MAXN];
int n, m, s, t;
bool vis[MAXN];
int d[MAXN];
bool spfa(){
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	memset(d, 0x3f, sizeof(d));
	queue<int>q;
	q.push(s); vis[s] = 1; d[s] = 0;
	while(!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int i = head[x]; i; i = edge[i].nxt) {
			if(edge[i].w <= 0) continue;
			int y = edge[i].to;
			if(d[x] + edge[i].cost < d[y]) {
				d[y] = d[x] + edge[i].cost;
				pre[y].v = x;
				pre[y].id = i;
				if(!vis[y]) {
					vis[y] = 1;
					q.push(y);
				}
			}
		}
	}
	return d[t] <= 1e9;
}
int main(){
	n = read(), m = read(), s = read(), t = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read(), c = read();
		add(x, y, z, c), add(y, x, 0, -c);
	}
	int ans = 0, maxflow = 0;
	while(spfa()) {
		int Min = 1e9;
		for(int i = t; i != s; i = pre[i].v)
			Min = min(Min, edge[pre[i].id].w);
		for(int i = t; i != s; i = pre[i].v) {
			edge[pre[i].id].w -= Min;
			edge[pre[i].id ^ 1].w += Min;
		}
		maxflow += Min;
		ans += Min * d[t];
	}
	printf("%d %d", maxflow, ans);
}
