#include <cstdio>
#include <iostream>
using namespace std;
const int MAXM = 1e5 + 5;
int n, m, a[MAXM], ans;
int f[25][1 << 20];
char s[25][MAXM];
int main() {
	scanf("%d%d\n", &n, &m);
	for (int i = 1; i <= n; i++) gets(s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			a[j] |= (s[i][j] ^ '0') << (i - 1);
	for(int i = 1; i <= m; i++) f[0][a[i]]++;
	for(int i = 0; i < n; i++)
		for(int j = n; j >= 1; j--)
			for(int k = 0; k < (1 << n); k++)
				f[j][k] += f[j - 1][k ^ (1 << i)];
	int ans = n * m;
	for(int i = 0; i < (1 << n); i++) {
		int tmp = 0;
		for(int j = 0; j < n; j++) tmp += min(n - j, j) * f[j][i];
		ans = min(ans, tmp);
	}
	printf("%d", ans);
}
