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
const int INF = 0x7fffffff;
const int MAXN = 205;
int nedge = 1, head[MAXN];
struct Edge {
	int w, to, nxt;
} edge[MAXN << 1];
struct Pre {
	int v, id;
} pre[MAXN];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
bool vis[MAXN];
bool bfs(int s, int t){
	memset(vis, 0, sizeof(vis));
	memset(pre, -1, sizeof(pre));
	queue<int>q;
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
	int m = read(), n = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		add(x, y, read()), add(y, x, 0);
	}
	int ans = 0;
	while(bfs(1, n)) {
		int Min = INF;
		for(int i = n; i != 1; i = pre[i].v)
			Min = min(Min, edge[pre[i].id].w);
		for(int i = n; i != 1; i = pre[i].v) {
			edge[pre[i].id].w -= Min;
			edge[pre[i].id ^ 1].w += Min;
		}
		ans += Min;
	}
	printf("%d", ans);
}
