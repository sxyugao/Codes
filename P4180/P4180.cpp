#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 1e5 + 5;
const int MAXM = 3e5 + 5;
const long long INF = 1e18;
int nedge, head[MAXN];
struct Edge {
	int to, w, nxt;
} edge[MAXN << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
struct E {
	int x, y, z;
	bool operator<(const E &b) const {
		return z < b.z;
	}
	void input(){
		x = read(), y = read(), z = read();
	}
} e[MAXM];
int n, m, f[MAXN];
int Find(int x){
	return f[x] = f[x] == x ? x : Find(f[x]);
}
bool used[MAXM];
int p[MAXN][25], Max[MAXN][25], Maxx[MAXN][25], d[MAXN];
void dfs(int x, int fa){
	p[x][0] = fa;
	d[x] = d[fa] + 1;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa) continue;
		Max[y][0] = edge[i].w;
		Maxx[y][0] = -0x7f7f7f7f;
		dfs(y, x);
	}
}
void work(){
	for(int j = 1; j <= 20; j++)
		for(int i = 1; i <= n; i++) {
			p[i][j] = p[p[i][j - 1]][j - 1];
			Max[i][j] = max(Max[i][j - 1], Max[p[i][j - 1]][j - 1]);
			Maxx[i][j] = max(Maxx[i][j - 1], Maxx[p[i][j - 1]][j - 1]);
			if(Max[i][j - 1] == Max[p[i][j - 1]][j - 1]) continue;
			if(Max[i][j - 1] > Max[p[i][j - 1]][j - 1]) Maxx[i][j] = max(Maxx[i][j], Max[p[i][j - 1]][j - 1]);
			else Maxx[i][j] = max(Maxx[i][j], Max[i][j - 1]);
		}
}
int LCA(int x, int y){
	if(d[x] < d[y]) swap(x, y);
	for(int i = 20; ~i; i--)
		if(d[p[x][i]] >= d[y]) x = p[x][i];
	if(x == y) return x;
	for(int i = 20; ~i; i--)
		if(p[x][i] ^ p[y][i]) {
			x = p[x][i], y = p[y][i];
		}
	return p[x][0];
}
int query(int x, int y, int z){
	int ans = -0x7f7f7f7f;
	for(int i = 20; ~i; i--)
		if(d[p[x][i]] >= d[y]) {
			if(z != Max[x][i]) ans = max(ans, Max[x][i]);
			else ans = max(ans, Maxx[x][i]);
			x = p[x][i];
		}
	return ans;
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++) e[i].input();
	sort(e + 1, e + m + 1);
	for(int i = 1; i <= n; i++) f[i] = i;
	long long sum = 0;
	for(int i = 1, cnt = 1; cnt < n && i <= m; i++) {
		int x = Find(e[i].x), y = Find(e[i].y);
		if(x == y) continue;
		add(e[i].x, e[i].y, e[i].z), add(e[i].y, e[i].x, e[i].z);
		f[x] = y;
		cnt++; sum += e[i].z;
		used[i] = 1;
	}
	Maxx[1][0] = -0x7f7f7f7f;
	dfs(1, 0);
	work();
	long long ans = INF;
	for(int i = 1; i <= m; i++) {
		if(used[i]) continue;
		int lca = LCA(e[i].x, e[i].y);
		int A = query(e[i].x, lca, e[i].z);
		int B = query(e[i].y, lca, e[i].z);
		ans = min(ans, sum - max(A, B) + e[i].z);
	}
	printf("%lld", ans);
}
