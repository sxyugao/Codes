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
int a[1005], g[1005][1005], f[1005];
int main(){
	int n = read(), m = read(), p = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int state = 1 << (a[1] - 1), cnt = 1;
	m = 1;
	for(int i = 2; i <= n; i++) {
		if(!(state & 1 << (a[i] - 1))) cnt++;
		state |= 1 << (a[i] - 1);
		if(cnt > p) {
			m++;
			cnt = 1;
			state = 1 << (a[i] - 1);
		}
	}
	printf("%d\n", m);
	memset(g, -1, sizeof(g));
	for(int i = 1; i <= n; i++) {
		state = 1 << (a[i] - 1);
		cnt = 1;
		g[i][i] = 1;
		for(int j = i + 1; j <= n; j++) {
			if(!(state & (1 << (a[j] - 1)))) cnt++;
			if(cnt > p) break;
			state |= 1 << (a[j] - 1);
			g[i][j] = cnt;
		}
	}
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			if(~g[j][i]) f[i] = min(f[i], f[j - 1] + g[j][i]);
	printf("%d", f[n]);
}
