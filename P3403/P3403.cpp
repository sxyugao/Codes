#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e5 + 5;
int nedge, head[MAXN];
struct Edge {
	int w, to, nxt;
} edge[MAXN << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
long long h, x, y, z, d[MAXN];
bool vis[MAXN];
int main(){
	scanf("%lld%lld%lld%lld", &h, &x, &y, &z);
	for(int i = 0; i < x; i++) {
		add(i, (i + y) % x, y);
		add(i, (i + z) % x, z);
	}
	memset(d, 0x3f, sizeof(d));
	queue<int>q;
	d[1 % x] = 1; q.push(1 % x); vis[1 % x] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if(d[y] > d[x] + edge[i].w) {
				d[y] = d[x] + edge[i].w;
				if(!vis[y]) {
					q.push(y);
					vis[y] = 1;
				}
			}
		}
	}
	long long ans = 0;
	for(int i = 0; i < x; i++)
		if(d[i] <= h) ans += 1LL * (h - d[i]) / x + 1;
	printf("%lld", ans);
}
