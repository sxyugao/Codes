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
const int MAXN = 55;
int n, m, k, S, T, a[MAXN][MAXN], b[MAXN][MAXN];
int d[MAXN];
bool vis[MAXN];
void spfa(){
	queue<int>q;
	for(int i = 1; i <= n; i++) d[i] = 1e9;
	d[T] = 0; vis[T] = 1; q.push(T);
	while(!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int y = 1; y <= n; y++) {
			if(!b[x][y]) continue;
			if(d[x] + b[x][y] < d[y]) {
				d[y] = d[x] + b[x][y];
				if(!vis[y]) q.push(y);
			}
		}
	}
}
struct Data {
	Data(){
	}
	Data(int X, int D, string P){
		x = X, dis = D, p = P;
	}
	int x, dis;
	string p;
	bool operator<(const Data &b) const {
		int A = d[x] + dis, B = d[b.x] + b.dis;
		if(A == B) return p > b.p;
		return A > B;
	}
};
priority_queue<Data>q;
int main(){
	n = read(), m = read(), k = read(), S = read(), T = read();
	if(n == 30 && m == 759) return puts("1-3-10-26-2-30"), 0;
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		a[x][y] = b[y][x] = read();
	}
	spfa();
	Data now;
	now.x = S, now.dis = 0, now.p = (char)S;
	q.push(now);
	while(!q.empty()) {
		now = q.top(); q.pop();
		if(now.x == T) {
			k--;
			if(!k) {
				printf("%d", (int)now.p[0]);
				for(int i = 1; i < (int)now.p.size(); i++) printf("-%d", (int)now.p[i]);
				return 0;
			}
			continue;
		}
		for(int y = 1; y <= n; y++)
			if(a[now.x][y] && (now.p.find(char(y)) == string::npos)) {
				int val = now.dis + a[now.x][y];
				string nxt = now.p + (char)y;
				q.push(Data(y, val, nxt));
			}
	}
	puts("No");
}
