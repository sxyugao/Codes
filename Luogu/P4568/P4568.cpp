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
const int MAXN = 1e4 + 5;
const int MAXM = 5e4 + 5;
int nedge, head[MAXN];
struct Edge {
	int to, w, nxt;
} edge[MAXM << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
bool vis[MAXN][15];
int d[MAXN][15];
struct Data {
	Data(){
	}
	Data(int X, int K){
		x = X, k = K;
	}
	int x, k;
	bool operator<(const Data &b) const {
		return d[x][k] > d[b.x][b.k];
	}
};
int main(){
	int n = read(), m = read(), k = read();
	int S = read() + 1, T = read() + 1;
	for(int i = 1; i <= m; i++) {
		int x = read() + 1, y = read() + 1, z = read();
		add(x, y, z), add(y, x, z);
	}
	memset(d, 0x3f, sizeof(d));
	d[S][0] = 0;
	priority_queue<Data>q;
	q.push(Data(S, 0));
	while(!q.empty()) {
		Data now = q.top(); q.pop();
		if(vis[now.x][now.k]) continue;
		for(int i = head[now.x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if(d[now.x][now.k] + edge[i].w < d[y][now.k]) {
				d[y][now.k] = d[now.x][now.k] + edge[i].w;
				if(!vis[y][now.k]) q.push(Data(y, now.k));
			}
			if(d[now.x][now.k] < d[y][now.k + 1] && now.k < k) {
				d[y][now.k + 1] = d[now.x][now.k];
				if(!vis[y][now.k + 1]) q.push(Data(y, now.k + 1));
			}
		}
	}
	printf("%d", d[T][k]);
}
