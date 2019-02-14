#include <cstdio>
int n, w[25], f[25], lst[25], a[25][25];
int dfs(int x){
	if(f[x]) return f[x];
	int ans = 0;
	for(int i = 1; i <= n; i++)
		if(a[x][i]) {
			int tmp = dfs(i);
			if(tmp > ans) {
				lst[x] = i;
				ans = tmp;
			}
		}
	return f[x] = ans + w[x];
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", w + i);
	for(int i = 1; i < n; i++)
		for(int j = i + 1; j <= n; j++)
			scanf("%d", &a[i][j]);
	int ans = 0, x = 0;
	for(int i = 1; i <= n; i++) {
		int tmp = dfs(i);
		if(tmp > ans) {
			ans = tmp;
			x = i;
		}
	}
	for(; x; x = lst[x]) printf("%d ", x);
	printf("\n%d", ans);
}
