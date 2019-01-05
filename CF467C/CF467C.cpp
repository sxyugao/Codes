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
const int MAXN = 5005;
long long a[MAXN], f[MAXN][MAXN];
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = a[i - 1] + read();
	for(int i = m; i <= n; i++)
		for(int j = 1; j <= k; j++)
			f[i][j] = max(f[i - 1][j], f[i - m][j - 1] + a[i] - a[i - m]);
	printf("%lld", f[n][k]);
}
