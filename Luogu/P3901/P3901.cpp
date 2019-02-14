#include <cmath>
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
int a[MAXN], lst[MAXN], f[MAXN];
int main(){
	int n = read(), q = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		f[i] = max(f[i - 1], lst[a[i]]);
		lst[a[i]] = i;
	}
	while(q--) {
		int l = read(), r = read();
		puts(l <= f[r] ? "No" : "Yes");
	}
}
