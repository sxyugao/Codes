#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long LL;
#define gc c = getchar()
LL read(){
	LL x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 5e5 + 5;
const int MAXM = 5e6 + 5;
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
bool vis[MAXN];
LL num, d[MAXN];
struct Data {
	Data(){
		x = d = 0;
	}
	Data(int X, LL D){
		x = X, d = D;
	}
	int x;
	LL d;
	bool operator<(const Data &b) const {
		return d > b.d;
	}
};
priority_queue<Data>q;
LL work(LL h){
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	q.push(Data(0, 0)); d[0] = 0;
	while(!q.empty()) {
		Data now = q.top(); q.pop();
		int x = now.x;
		if(vis[x]) continue;
		vis[x] = 1;
		for(int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].to;
			if(d[x] + edge[i].w < d[y]) {
				d[y] = d[x] + edge[i].w;
				if(!vis[y]) q.push(Data(y, d[y]));
			}
		}
	}
	LL ans = 0;
	for(int i = 0; i < num; i++)
		if(d[i] <= h) ans += (h - d[i]) / num + 1;
	return ans;
}
int main(){
	LL n = read(), L = read(), R = read();
	num = read();
	for(int i = 1; i < n; i++) {
		int x = read();
		for(int i = 0; i < num; i++)
			add(i, (i + x) % num, x);
	}
	printf("%lld", work(R) - work(L - 1));
}
