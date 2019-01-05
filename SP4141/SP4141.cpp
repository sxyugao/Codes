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
const int MAXN = 1e6;
int n, f[MAXN + 5];
bool pri[MAXN + 5];
int main(){
	for(int i = 1; i <= MAXN; i++) f[i] = i, pri[i] = 1;
	for(int i = 2; i <= MAXN; i++)
		if(pri[i]) {
			for(int j = 1; i * j <= MAXN; j++) {
				pri[i * j] = 0;
				f[i * j] = f[i * j] / i * (i - 1);
			}
		}
	for(int T = read(); T; T--) printf("%d\n", f[read()]);
}
