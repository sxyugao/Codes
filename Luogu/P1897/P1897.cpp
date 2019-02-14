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
int a[100005];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	sort(a + 1, a + n + 1);
	int ans = a[n] * 10 + n;
	ans += 5 * (unique(a + 1, a + n + 1) - a - 1);
	ans -= (a[1] == 0) * 5;
	printf("%d", ans);
}
