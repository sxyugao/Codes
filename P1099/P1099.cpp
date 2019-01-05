#include <vector>
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
int nedge, head[305];
struct Edge {
	int to, nxt, w;
} e[605];
void add(int x, int y, int z){
	e[++nedge].to = y;
	e[nedge].w = z;
	e[nedge].nxt = head[x];
	head[x] = nedge;
}
int n, s, a[305][305];
vector<int>v, edge;
bool flag, vis[305];
void dfs(int x, int tar, int fa){
	if(x == tar) {
		flag = 1;
		return;
	}
	for(int i = head[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if(y == fa) continue;
		v.push_back(y); edge.push_back(e[i].w);
		dfs(y, tar, x);
		if(flag) return;
		v.pop_back(); edge.pop_back();
	}
}
int Find(int x, int fa, int dist){
	if(vis[x]) return dist;
	for(int i = head[x]; i; i = e[i].nxt) {
		int y = e[i].to;
		if(y == fa) continue;
		int ans = Find(y, x, dist + e[i].w);
		if(ans) return ans;
	}
	return 0;
}
int main(){
	n = read(), s = read();
	memset(a, 0x3f, sizeof(a));
	for(int i = 1; i < n; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z); add(y, x, z);
		a[x][y] = a[y][x] = z;
	}
	for(int i = 1; i <= n; i++) a[i][i] = 0;
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	int len = 0;
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++)
			len = max(len, a[i][j]);
	int ans = 1e9;
	for(int ii = 1; ii <= n; ii++)
		for(int jj = ii + 1; jj <= n; jj++)
			if(a[ii][jj] == len) {
				v.push_back(ii);
				dfs(ii, jj, 0);
				int dis = 0, p = 0;
				memset(vis, 0, sizeof(vis));
				for(int k = 0; k < (int)v.size(); k++) {
					vis[v[k]] = 1;
					while(p < (int)edge.size() && dis + edge[p] <= s) dis += edge[p], p++, vis[v[p]] = 1;
					int tmp = 0;
					for(int i = 1; i <= n; i++)
						if(!vis[i]) tmp = max(tmp, Find(i, 0, 0));
					ans = min(ans, tmp);
					if(p > k) dis -= edge[k];
					p = max(p, k + 1);
					vis[v[k]] = 0;
				}
				printf("%d", ans);
				return 0;
			}
}
