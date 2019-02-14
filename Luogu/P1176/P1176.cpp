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
const int P = 100003;
bool d[1005][1005];
int f[1005][1005];
int main(){
	int n = read(), m = read();
	while(m--) {
		int x = read(), y = read();
		d[x][y] = 1;
	}
	for(int i = 1; i <= n && !d[i][1]; i++) f[i][1] = 1;
	for(int i = 1; i <= n && !d[1][i]; i++) f[1][i] = 1;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if(i == 1 || j == 1) continue;
			if(d[i][j]) continue;
			f[i][j] = (f[i - 1][j] + f[i][j - 1]) % P;
		}
	printf("%d", f[n][n]);
}
