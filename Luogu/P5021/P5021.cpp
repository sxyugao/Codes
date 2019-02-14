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
const int MAXN = 5e4 + 5;
int nedge, head[MAXN];
struct Edge {
	int to, nxt, w;
} edge[MAXN << 1];
void add(int x, int y, int z){
	edge[++nedge].to = y;
	edge[nedge].w = z;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
int n, m, cnt;
int dfs(int x, int fa, int num){
	vector<int>v;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		if(y == fa) continue;
		v.push_back(edge[i].w + dfs(y, x, num));
	}
	sort(v.begin(), v.end());
	multiset<int>s;
	for(int x : v) {
		if(x >= num) {
			cnt++;
			continue;
		}
		auto it = s.lower_bound(num - x);
		if(it != s.end()) {
			s.erase(it);
			cnt++;
		}else s.insert(x);
	}
	return (s.size() ? *s.rbegin() : 0);
}
bool check(int x){
	cnt = 0;
	dfs(1, 0, x);
	return cnt >= m;
}
int main(){
	n = read(), m = read();
	for(int i = 1; i < n; i++) {
		int x = read(), y = read(), z = read();
		add(x, y, z), add(y, x, z);
	}
	int l = 0, r = 10000 * n, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", ans);
}
