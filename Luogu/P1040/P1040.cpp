#include <cstdio>
#include <iostream>
using namespace std;
int n, a[30], f[30][30], g[30][30];
int dfs(int l, int r){
	if(l > r) return 1;
	if(f[l][r]) return f[l][r];
	for(int i = l; i < r; i++) {
		int tmp = dfs(l, i - 1) * dfs(i + 1, r) + a[i];
		if(tmp > f[l][r]) {
			f[l][r] = tmp;
			g[l][r] = i;
		}
	}
	return f[l][r];
}
void print(int l, int r){
	if(l > r) return;
	printf("%d ", g[l][r]);
	print(l, g[l][r] - 1);
	print(g[l][r] + 1, r);
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) f[i][i] = a[i], g[i][i] = i;
	printf("%d\n", dfs(1, n));
	print(1, n);
}
