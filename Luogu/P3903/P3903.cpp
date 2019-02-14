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
int a[1005], f[1005][2];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	f[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i] > a[i - 1]) f[i][1] = f[i - 1][0] + 1;
		else f[i][1] = f[i - 1][1];
		if(a[i] < a[i - 1]) f[i][0] = f[i - 1][1] + 1;
		else f[i][0] = f[i - 1][0];
	}
	printf("%d", max(f[n][0], f[n][1]));
}
