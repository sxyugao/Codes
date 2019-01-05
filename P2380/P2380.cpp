#include <bits/stdc++.h>
using namespace std;
int n, m;
long long a[1005][1005], b[1005][1005], f[1005][1005];
int main(){
	while(scanf("%d%d", &n, &m), n && m) {
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				int x;
				scanf("%d", &x);
				a[i][j] = a[i][j - 1] + x;
			}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++) {
				int x;
				scanf("%d", &x);
				b[i][j] = b[i - 1][j] + x;
			}
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= m; j++)
				f[i][j] = max(f[i - 1][j] + a[i][j], f[i][j - 1] + b[i][j]);
		printf("%lld\n", f[n][m]);
	}
}
