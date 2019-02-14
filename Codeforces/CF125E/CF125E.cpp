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
struct Edge {
	int x, y, w, id;
	bool c;
	bool operator<(const Edge &b) const {
		if(w != b.w) return w < b.w;
		return c < b.c;
	}
} edge[100005];
int f[5005];
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
		f[a] = b; num++;
		if(!edge[i].c) cnt++;
	}
	for(int i = 1; i <= m; i++)
		if(!edge[i].c) edge[i].w -= x;
	return cnt >= k;
}
void Ans(int x){
	for(int i = 1; i <= m; i++)
		if(!edge[i].c) edge[i].w += x;
	for(int i = 1; i <= n; i++) f[i] = i;
	sort(edge + 1, edge + m + 1);
	int cnt = 0;
	printf("%d\n", n - 1);
	for(int i = 1; i <= m && n > 1; i++) {
		int a = Find(edge[i].x), b = Find(edge[i].y);
		if(a == b) continue;
		if(!edge[i].c && cnt == k) continue;
		if(!edge[i].c) cnt++;
		f[a] = b; n--;
		printf("%d ", edge[i].id);
	}
}
int main(){
	n = read(), m = read(), k = read();
	int cnt = 0;
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read(), z = read();
		if(x > y) swap(x, y);
		edge[i].x = x; edge[i].y = y;
		edge[i].w = z; edge[i].c = x != 1;
		edge[i].id = i;
		cnt += x == 1;
	}
	if(cnt < k || (!k && n > 1)) return puts("-1"), 0;
	int l = -1e5, r = 1e5, ans = 0x3f3f3f3f;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	Ans(ans);
}
