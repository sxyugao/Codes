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
const int MAXN = 5005;
struct edge {
	int x, y;
} edge[MAXN];
vector<int>v[MAXN];
int n, m, tx, ty, num;
int ans[MAXN], k[MAXN];
bool vis[MAXN];
void dfs(int x, int fa){
	if(vis[x]) return;
	vis[x] = 1;
	k[++num] = x;
	for(int y : v[x]) {
		if(y == fa) continue;
		if((y == ty && x == tx) || (y == tx && x == ty)) continue;
		dfs(y, x);
	}
}
bool check(){
	for(int i = 1; i <= n; i++) {
		if(k[i] == ans[i]) continue;
		if(k[i] > ans[i]) return 0;
		else return 1;
	}
	return 1;
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		v[x].push_back(y);
		v[y].push_back(x);
		edge[i].x = x, edge[i].y = y;
	}
	for(int i = 1; i <= n; i++) sort(v[i].begin(), v[i].end());
	memset(ans, 0x3f, sizeof(ans));
	if(n == m) {
		for(int i = 1; i <= m; i++) {
			num = 0; tx = edge[i].x; ty = edge[i].y;
			memset(vis, 0, sizeof(vis));
			dfs(1, 0);
			if(num < n || !check()) continue;
			for(int i = 1; i <= n; i++) ans[i] = k[i];
		}
		for(int i = 1; i <= n; i++) printf("%d ", ans[i]);
		return 0;
	}
	dfs(1, 0);
	for(int i = 1; i <= n; i++) printf("%d ", k[i]);
}
