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
int a[100005];
int main(){
	int n = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = 1;
	for(int m = read(); m; m--) a[read()] = 0;
	for(int i = 1; i <= n; i++) a[i] += a[i - 1];
	int ans = 0x7fffffff;
	for(int i = k; i <= n; i++) ans = min(ans, k - (a[i] - a[i - k]));
	printf("%d", ans);
}
