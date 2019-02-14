#include <map>
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
const int MAXN = 100005;
string s;
map<string, int>a;
int id[MAXN], c[MAXN], cost[MAXN];
int main(){
	int n = read(), k = read(), m = read();
	for(int i = 1; i <= n; i++) {
		cin >> s;
		a[s] = i;
	}
	for(int i = 1; i <= n; i++) cost[i] = read();
	for(int i = 1; i <= k; i++) {
		c[i] = 0x7fffffff;
		int x = read();
		while(x--) {
			int xx = read();
			id[xx] = i;
			c[i] = min(c[i], cost[xx]);
		}
	}
	long long ans = 0;
	for(int i = 1; i <= m; i++) {
		cin >> s;
		ans += 1LL * c[id[a[s]]];
	}
	printf("%lld", ans);
}
