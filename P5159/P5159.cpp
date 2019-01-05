#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
inline int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int P = 998244353;
inline int pw(int a, long long n){
	int ans = 1;
	while(n) {
		if(n & 1) ans = 1LL * ans * a % P;
		a = 1LL * a * a % P;
		n >>= 1;
	}
	return ans;
}
int main(){
	for(int T = read(); T; T--) {
		int n = read(), m = read();
		printf("%d\n", pw(2, 1LL * (n - 1) * (m - 1)));
	}
}
