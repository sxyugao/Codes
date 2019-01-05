#include <bits/stdc++.h>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 300005;
int a[MAXN];
bool vis[MAXN];
int main(){
	int n = read(), ans = 0, p = n;
	putchar('1');
	for(int i = 1; i <= n; i++) {
		vis[read()] = 1;
		ans++;
		while(vis[p]) ans--, p--;
		printf(" %d", ans + 1);
	}
}
