#include <queue>
#include <cstdio>
#include <cstdlib>
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
const int MAXN = 1005;
int n, m;
int head[MAXN];
struct Edge {
	int to, nxt, w;
} edge[10005];
int spfa(int s, int t){
	static int d[MAXN];
	static int cnt[MAXN];
	static bool vis[MAXN];
	queue<int>q;
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	memset(cnt, 0, sizeof(cnt));
	while(!q.empty()) q.pop();
	q.push(s); d[s] = 0; cnt[s] = 1; vis[s] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		if(cnt[x] >= n) {
			puts("Forever love");
			exit(0);
		}
		for(int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if(d[x] + edge[i].w < d[y]) {
				d[y] = d[x] + edge[i].w;
				if(!vis[y]) {
					vis[y] = 1;
					q.push(y);
					cnt[y]++;
				}
			}
		}
	}
	return d[t];
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read();
		edge[i].to = y;
		edge[i].w = -z;
		edge[i].nxt = head[x];
		head[x] = i;
	}
	printf("%d", min(spfa(1, n), spfa(n, 1)));
}
