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
const int MAXN = 1e5 + 5;
int head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN];
int a[MAXN];
void dfs(int cur, int x){
	if(a[x] >= cur) return;
	a[x] = cur;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		dfs(cur, y);
	}
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int y = read(), x = read();
		edge[i].to = y;
		edge[i].nxt = head[x];
		head[x] = i;
	}
	for(int i = n; i; i--) dfs(i, i);
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}
