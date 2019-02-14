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
const int MAXN = 300005;
int a[MAXN], b[MAXN];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int m = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	long long A = 0, B = 0;
	int p1 = 0, p2 = 0, ans = 0;
	while(p1 < n) {
		A += a[++p1];
		while(A > B && p2 < m) B += b[++p2];
		if(A == B) ans++;
	}
	while(p2 < m) B += b[++p2];
	if(A != B) return puts("-1"), 0;
	printf("%d", ans);
}
