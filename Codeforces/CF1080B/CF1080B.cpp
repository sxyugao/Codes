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
	for(int T = read(); T; T--) {
		int l = read() - 1, r = read();
		long long L = l / 2 - (l & 1 ? l : 0);
		long long R = r / 2 - (r & 1 ? r : 0);
		printf("%lld\n", R - L);
	}
}
