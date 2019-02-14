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
	int n = read(), a = read(), b = read(), c = read(), d = read(), x = read();
	int even = 0, odd = 0;
	for(int i = 1; i <= n; i++) {
		x = (1LL * a * x % d * x % d + 1LL * b * x % d + c) % d;
		if(__builtin_parity(x)) odd++;
		else even++;
	}
	printf("%lld", 1LL * odd * even);
}
