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
int main(){
	long long ans = 0;
	int lst = 0;
	for(int n = read(); n; n--) {
		int x = read();
		ans += max(0, x - lst);
		lst = x;
	}
	printf("%lld", ans);
}
