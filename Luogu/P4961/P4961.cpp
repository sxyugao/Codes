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
const int dx[] = {1, 0, -1, 0, -1, -1, 1, 1};
const int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
int n, m, a[1005][1005], b[1005][1005];
bool vis[1005][1005];
void dfs(int x, int y){
	if(x < 1 || x > n || y < 1 || y > m) return;
	if(b[x][y] || vis[x][y]) return;
	vis[x][y] = 1;
	for(int i = 0; i < 8; i++) dfs(x + dx[i], y + dy[i]);
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			a[i][j] = read();
			if(a[i][j]) b[i][j] = -1;
		}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 0; k < 8 && a[i][j]; k++) {
				int tx = i + dx[k], ty = j + dy[k];
				if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if(a[tx][ty]) continue;
				b[tx][ty]++;
			}
	int ans = 0;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(!b[i][j] && !vis[i][j]) ans++, dfs(i, j);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(b[i][j] <= 0) continue;
			bool f = 1;
			for(int k = 0; k < 8; k++) {
				int tx = i + dx[k], ty = j + dy[k];
				if(tx < 1 || tx > n || ty < 1 || ty > m) continue;
				if(b[tx][ty] == 0) f = 0;
			}
			if(f) ans++;
		}
	printf("%d", ans);
}
