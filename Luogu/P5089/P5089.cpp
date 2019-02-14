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
int f[400005];
int Find(int k){
	return f[k] == k ? k : f[k] = Find(f[k]);
}
int main(){
	int n = read(), m = read(), q = read();
	for(int i = 1; i <= n + m; i++) f[i] = i;
	while(q--) {
		int x = Find(read()), y = Find(read() + n);
		f[x] = y;
	}
	int ans = n + m - 1;
	for(int i = 1; i <= n + m; i++)
		if(Find(i) != i) ans--;
	printf("%d", ans);
}
