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
const int MAXN = 50005;
struct Edge {
	int x, y, w, c;
	bool operator<(const Edge &b) const {
		if(w != b.w) return w < b.w;
		return c < b.c;
	}
} edge[MAXN << 1];
int f[MAXN];
int Find(int x){
	return f[x] == x ? x : f[x] = Find(f[x]);
}
int n, m, k;
bool check(int x){
	for(int i = 1; i <= m; i++)
		if(!edge[i].c) edge[i].w += x;
	for(int i = 1; i <= n; i++) f[i] = i;
	sort(edge + 1, edge + m + 1);
	int cnt = 0;
	for(int num = 1, i = 1; i <= m && num < n; i++) {
		int a = Find(edge[i].x), b = Find(edge[i].y);
		if(a == b) continue;
		f[a] = b;
		num++;
		if(!edge[i].c) cnt++;
	}
	for(int i = 1; i <= m; i++)
		if(!edge[i].c) edge[i].w -= x;
	return cnt >= k;
}
int Ans(int x){
	for(int i = 1; i <= m; i++)
		if(!edge[i].c) edge[i].w += x;
	for(int i = 1; i <= n; i++) f[i] = i;
	sort(edge + 1, edge + m + 1);
	int ans = 0;
	for(int num = 1, i = 1; i <= m && num < n; i++) {
		int a = Find(edge[i].x), b = Find(edge[i].y);
		if(a == b) continue;
		f[a] = b;
		num++;
		ans += edge[i].w;
	}
	return ans - k * x;
}
int main(){
	n = read(), m = read(), k = read();
	for(int i = 1; i <= m; i++) {
		int x = read() + 1, y = read() + 1, z = read(), c = read();
		if(x > y) swap(x, y);
		edge[i].x = x; edge[i].y = y;
		edge[i].w = z; edge[i].c = c;
	}
	int l = -100, r = 101, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	printf("%d", Ans(ans));
}
