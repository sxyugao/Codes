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
int sqr(int x){
	return x * x;
}
struct Data {
	int x, y, d1, d2;
	bool operator<(const Data &b) const {
		return d1 < b.d1;
	}
} a[100005];
int f[100005];
int main(){
	int x1 = read(), y1 = read(), x2 = read(), y2 = read();
	int n = read();
	for(int i = 1; i <= n; i++) {
		a[i].x = read(), a[i].y = read();
		a[i].d1 = sqr(x1 - a[i].x) + sqr(y1 - a[i].y);
		a[i].d2 = sqr(x2 - a[i].x) + sqr(y2 - a[i].y);
	}
	sort(a + 1, a + n + 1);
	for(int i = n; i; i--) f[i] = max(f[i + 1], a[i].d2);
	int ans = 0x7fffffff;
	for(int i = 1; i <= n; i++) ans = min(a[i].d1 + f[i + 1], ans);
	printf("%d", ans);
}
