#include <cstdio>
#include <cstring>
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
const int MAXN = 10005;
int a[MAXN];
bool f[MAXN][100];
int main(){
	for(int T = read(); T; T--) {
		int n = read(), m = read();
		for(int i = 1; i <= n; i++) a[i] = read();
		memset(f, 0, sizeof(f));
		f[0][0] = 1;
		for(int i = 1; i <= n; i++)
			for(int j = 0; j < m; j++) {
				f[i][j] |= f[i - 1][((j + a[i]) % m + m) % m];
				f[i][j] |= f[i - 1][((j - a[i]) % m + m) % m];
			}
		puts(f[n][0] ? "Divisible" : "Not divisible");
	}
}
