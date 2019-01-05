#include <cstdio>
int n, m, ans;
bool vis[105];
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		for(int j = x; j <= y; j++) vis[j] = 1;
	}
	for(int i = 1; i <= m; i++)
		if(!vis[i]) ans++;
	printf("%d\n", ans);
	for(int i = 1; i <= m; i++)
		if(!vis[i]) printf("%d ", i);
}
