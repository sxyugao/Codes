#include <bits/stdc++.h>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2)) ? EOF : *p1++;
}
#define gc c = _gc()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;
int nedge, head[MAXN];
struct Edge {
	int x, y, nxt, w, h;
	bool operator<(const Edge &b) const {
		return h > b.h;
	}
} edge[MAXM << 1];
void add(int x, int y, int w, int h){
	nedge++;
	edge[nedge].y = y, edge[nedge].x = x;
	edge[nedge].w = w, edge[nedge].h = h;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
struct Heap {
	Heap(){
		x = d = 0;
	}
	Heap(int X, int D){
		x = X, d = D;
	}
	int x, d;
	bool operator<(const Heap &b) const {
		return d > b.d;
	}
};
bool vis[MAXN];
int n, m, d[MAXN];
priority_queue<Heap>q;
void dijkstra(){
	q.push(Heap(1, 0)); d[1] = 0;
	while(!q.empty()) {
		Heap now = q.top(); q.pop();
		int x = now.x;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].y;
			if(d[x] + edge[i].w < d[y]) {
				d[y] = d[x] + edge[i].w;
				q.push(Heap(y, d[y]));
			}
		}
	}
}
int lstans;
struct Data {
	Data(){
	}
	Data(int H, int Ans){
		h = H;
		ans = Ans;
	}
	int h, ans;
};
vector<Data>v[MAXN];
int fa[MAXN], dep[MAXN], hh[MAXN];
int Find(int x){
	while(fa[x]) x = fa[x];
	return x;
}
void insert(int x, int ans, int h){
	if(ans < (--v[x].end())->ans) v[x].push_back(Data(h, ans));
}
void Merge(int x, int y, int h){
	x = Find(x), y = Find(y);
	if(x == y) return;
	if(dep[x] > dep[y]) swap(x, y);
	fa[x] = y; hh[x] = h;
	dep[y] = max(dep[x] + 1, dep[y]);
	insert(y, (--v[x].end())->ans, h);
}
int solve(int x, int h){
	while(fa[x] && hh[x] > h) x = fa[x];
	int l = 0, r = v[x].size() - 1, ans = 0x7fffffff;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(v[x][mid].h > h) ans = min(ans, v[x][mid].ans), l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
void work(){
	n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), l = read(), h = read();
		add(x, y, l, h), add(y, x, l, h);
	}
	dijkstra();
	sort(edge + 1, edge + nedge + 1);
	for(int i = 1; i <= n; i++) {
		v[i].clear();
		v[i].push_back(Data(0x7fffffff, d[i]));
	}
	for(int i = 1; i <= nedge; i++) Merge(edge[i].x, edge[i].y, edge[i].h);
	int q = read(), K = read(), S = read();
	while(q--) {
		int v = (read() + K * lstans - 1) % n + 1;
		int p = (read() + K * lstans) % (S + 1);
		printf("%d\n", lstans = solve(v, p));
	}
}
void init(){
	memset(head, 0, sizeof(head));
	memset(vis, 0, sizeof(vis));
	memset(dep, 0, sizeof(dep));
	memset(fa, 0, sizeof(fa));
	memset(d, 0x3f, sizeof(d));
	nedge = lstans = 0;
}
int main(){
	for(int T = read(); T; T--) init(), work();
}
