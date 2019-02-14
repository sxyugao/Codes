#include <vector>
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
const int MAXN = 1e6 + 5;
int n, k, ans;
int deg[MAXN];
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int dfs(int x, int f){
	if(deg[x] == 1) return 0;
	vector<int>v;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == f) continue;
		v.push_back(dfs(y, x) + 1);
	}
	sort(v.begin(), v.end());
	for(int i = v.size() - 1; i >= 1; i--) {
		if(v[i] + v[i - 1] <= k) return v[i];
		ans++;
	}
	return v[0];
}
int main(){
	n = read(), k = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read();
		add(x, y), add(y, x);
		deg[x]++, deg[y]++;
	}
	for(int i = 1; i <= n; i++)
		if(deg[i] > 1) {
			dfs(i, 0);
			break;
		}
	printf("%d", ans + 1);
}
