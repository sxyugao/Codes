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
int n, m, f[10][1 << 6];
int num, s[1 << 6], a[10][10];
void init(int k, bool lst, int state){
	if(k > m) {
		s[++num] = state;
		return;
	}
	init(k + 1, 0, state);
	if(!lst) init(k + 1, 1, state | (1 << (k - 1)));
}
int main(){
	for(int T = read(); T; T--) {
		n = read(), m = read();
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				a[i][j] = read();
		num = 0;
		init(1, 0, 0);
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= num; j++)
				for(int k = 1; k <= num; k++) {
					if(s[k] & s[j] || (s[k] << 1) & s[j] || (s[k] >> 1) & s[j]) continue;
					int x = 0;
					for(int p = 1; p <= m; p++)
						if((1 << (p - 1)) & s[k]) x += a[i][p];
					f[i][s[k]] = max(f[i][s[k]], f[i - 1][s[j]] + x);
				}
		int ans = 0;
		for(int i = 1; i <= num; i++) ans = max(ans, f[n][s[i]]);
		printf("%d\n", ans);
	}
}
