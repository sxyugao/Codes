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
int a[55], f[55][55];
int main(){
	while((a[0] = read())) {
		int n = read();
		for(int i = 1; i <= n; i++) a[i] = read();
		a[n + 1] = a[0]; a[0] = 0;
		memset(f, 0x3f, sizeof(f));
		for(int i = 1; i <= n + 1; i++) f[i][i] = 0;
		for(int i = n + 1; i; i--)
			for(int j = i + 1; j <= n + 1; j++)
				for(int k = i; k < j; k++)
					f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + a[j] - a[i - 1]);
		printf("The minimum cutting is %d.\n", f[1][n + 1]);
	}
}
