#include <bits/stdc++.h>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m, T, a[35][35];
struct Data {
	Data(){
	}
	Data(int X, int Y){
		x = X, y = Y;
	}
	int x, y;
};
int id(int x, int y, int d){
	return x * 900 + y * 30 + d;
}
int nedge, head[50000];
struct Edge {
	int to, nxt, w;
} edge[100005];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int dis[35][35];
void bfs(int ex, int ey, int sx, int sy, int d){
	static queue<Data>q;
	while(!q.empty()) q.pop();
	memset(dis, -1, sizeof(dis));
	dis[ex][ey] = 0;
	dis[sx][sy] = 1;
	q.push(Data(ex, ey));
	while(!q.empty()) {
		Data now = q.front(); q.pop();
		for(int i = 0; i < 4; i++) {
			int pp = now.x + dx[i];
			int qq = now.y + dy[i];
			if(pp < 1 || pp > n || qq < 1 || qq > m) continue;
			if(!a[pp][qq] || ~dis[pp][qq]) continue;
			dis[pp][qq] = dis[now.x][now.y] + 1;
			q.push(Data(pp, qq));
		}
	}
	if(d < 0) return;
	for(int i = 0; i < 4; i++) {
		int pp = sx + dx[i], qq = sy + dy[i];
		if(!(pp == ex && qq == ey) && ~dis[pp][qq])
			add(id(sx, sy, d), id(sx, sy, i), dis[pp][qq]);
	}
	add(id(sx, sy, d), id(ex, ey, (d + 2) % 4), 1);
}
int d[50000];
bool vis[50000];
void spfa(int x, int y){
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	static queue<int>q;
	for(int i = 0; i < 4; i++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(~dis[tx][ty]) {
			d[id(x, y, i)] = dis[tx][ty];
			vis[id(x, y, i)] = 1;
			q.push(id(x, y, i));
		}
	}
	while(!q.empty()) {
		int now = q.front(); q.pop(); vis[now] = 0;
		for(int i = head[now]; i; i = edge[i].nxt) {
			int u = edge[i].to;
			if(d[now] + edge[i].w < d[u]) {
				d[u] = d[now] + edge[i].w;
				if(!vis[u]) {
					vis[u] = 1;
					q.push(u);
				}
			}
		}
	}
}
int solve(){
	int ex = read(), ey = read(), sx = read(), sy = read(), tx = read(), ty = read();
	if(sx == tx && sy == ty) return 0;
	bfs(ex, ey, sx, sy, -1);
	spfa(sx, sy);
	int ans = 0x3f3f3f3f;
	for(int i = 0; i < 4; i++) ans = min(ans, d[id(tx, ty, i)]);
	if(ans < 1e9) return ans;
	return -1;
}
int main(){
	n = read(), m = read(), T = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[i][j] = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(a[i][j]) {
				if(a[i + 1][j]) bfs(i + 1, j, i, j, 0);
				if(a[i][j + 1]) bfs(i, j + 1, i, j, 1);
				if(a[i - 1][j]) bfs(i - 1, j, i, j, 2);
				if(a[i][j - 1]) bfs(i, j - 1, i, j, 3);
			}
	while(T--) printf("%d\n", solve());
}
