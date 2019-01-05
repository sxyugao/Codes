#include <queue>
#include <cstdio>
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
const int MAXN = 1e5 + 5;
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
long long d[MAXN];
int nxt[MAXN];
bool vis[MAXN];
struct cmp {
	bool operator()(const int &a, const int &b){
		return d[a] > d[b];
	}
};
priority_queue<int, vector<int>, cmp>q;
void print(int x){
	if(!x) return;
	print(nxt[x]);
	printf("%d ", x);
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z);
	}
	for(int i = 1; i <= n; i++) d[i] = 1e18;
	d[1] = 0;
	q.push(1);
	while(!q.empty()) {
		int x = q.top(); q.pop();
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if(d[x] + edge[i].w < d[y]) {
				d[y] = d[x] + edge[i].w;
				nxt[y] = x;
				if(!vis[y]) q.push(y);
			}
		}
	}
	if(d[n] < 1e18) print(n);
	else puts("-1");
}
