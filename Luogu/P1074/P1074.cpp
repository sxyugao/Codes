#include <cstdio>
#include <iostream>
using namespace std;
int tmp, ans, a[10][10], rest[10][10];
bool vis[10][10], used[10][10][10], row[10][10], line[10][10];
int score[10][10] = {
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{0, 6, 6, 6, 6, 6, 6, 6, 6, 6},
	{0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
	{0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
	{0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
	{0, 6, 7, 8, 9, 10, 9, 8, 7, 6},
	{0, 6, 7, 8, 9, 9, 9, 8, 7, 6},
	{0, 6, 7, 8, 8, 8, 8, 8, 7, 6},
	{0, 6, 7, 7, 7, 7, 7, 7, 7, 6},
	{0, 6, 6, 6, 6, 6, 6, 6, 6, 6}
};
void dfs();
void solve(int, int, int, int);
void dfs(){
	int L = 0, R = 0;
	for(int i = 1; i <= 9; i += 3)
		for(int j = 1; j <= 9; j += 3)
			if(!vis[i][j] && rest[i][j] < rest[L][R]) L = i, R = j;
	if(!L && !R) return (void)(ans = max(ans, tmp));
	vis[L][R] = 1;
	solve(L, R, 0, 0);
	vis[L][R] = 0;
}
void solve(int L, int R, int x, int y){
	if(x > 2) return dfs();
	if(y > 2) return solve(L, R, x + 1, 0);
	if(a[L + x][R + y]) {
		if(used[L][R][a[L + x][R + y]]) return;
		used[L][R][a[L + x][R + y]] = 1;
		tmp += a[L + x][R + y] * score[L + x][R + y];
		solve(L, R, x, y + 1);
		tmp -= a[L + x][R + y] * score[L + x][R + y];
		used[L][R][a[L + x][R + y]] = 0;
		return;
	}
	for(int i = 1; i <= 9; i++)
		if(!(used[L][R][i] || line[L + x][i] || row[R + y][i])) {
			used[L][R][i] = line[L + x][i] = row[R + y][i] = 1;
			a[L + x][R + y] = i;
			tmp += i * score[L + x][R + y];
			solve(L, R, x, y + 1);
			tmp -= i * score[L + x][R + y];
			a[L + x][R + y] = 0;
			used[L][R][i] = line[L + x][i] = row[R + y][i] = 0;
		}
}
int main(){
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++) {
			scanf("%d", &a[i][j]);
			line[i][a[i][j]] = a[i][j];
		}
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			row[i][a[j][i]] = a[j][i];
	rest[0][0] = 1e9;
	for(int i = 1; i <= 9; i += 3)
		for(int j = 1; j <= 9; j += 3)
			for(int p = i; p <= i + 2; p++)
				for(int q = j; q <= j + 2; q++)
					if(!a[p][q]) rest[i][j]++;
	ans = -1;
	dfs();
	printf("%d", ans);
}
