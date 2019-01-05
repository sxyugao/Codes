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
int d[505], a[505][505];
bool vis[505];
int main(){
	int w = read(), n = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = read();
	d[0] = 1e9;
	for(int i = 1; i <= n; i++) d[i] = w;
	for(int i = 1; i <= n; i++) {
		int k = 0;
		for(int j = 1; j <= n; j++)
			if(!vis[j] && d[j] < d[k]) k = j;
		vis[k] = 1;
		for(int j = 1; j <= n; j++)
			if(a[k][j] && !vis[j] && a[k][j] < d[j]) d[j] = a[k][j];
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) ans += d[i];
	printf("%d", ans);
}
