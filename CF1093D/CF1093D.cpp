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
const int MAXN = 3e5 + 5;
const int P = 998244353;
int pw(int a, int n){
	int ans = 1;
	while(n) {
		if(n & 1) ans = 1LL * ans * a % P;
		a = 1LL * a * a % P;
		n >>= 1;
	}
	return ans;
}
int nedge, head[MAXN];
struct Edge {
	int to, nxt;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = head[x];
	head[x] = nedge;
}
bool f;
int cnt0, cnt1, col[MAXN];
void dfs(int x, int c){
	if(col[x]) {
		if(c != col[x]) f = 0;
		return;
	}
	col[x] = c;
	if(c & 1) cnt1++; else cnt0++;
	for(int i = head[x]; i; i = edge[i].nxt) {
		int y = edge[i].to;
		dfs(y, c ^ 1);
		if(!f) return;
	}
}
int main(){
	for(int T = read(); T; T--) {
		int n = read(), m = read();
		nedge = 0;
		for(int i = 1; i <= n; i++) head[i] = 0;
		for(int i = 1; i <= n; i++) col[i] = 0;
		for(int i = 1; i <= m; i++) {
			int x = read(), y = read();
			add(x, y), add(y, x);
		}
		int ans = 1;
		f = 1;
		for(int i = 1; i <= n; i++)
			if(!col[i]) {
				cnt0 = 0, cnt1 = 0;
				dfs(i, 2);
				int tmp = f * (pw(2, cnt0) + pw(2, cnt1)) % P;
				ans = 1LL * ans * tmp % P;
			}
		printf("%d\n", ans);
	}
}
