#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};
int n, m;
char s[25][25];
bool vis[25][25][4][20];
void dfs(int x, int y, int d, int num){
	if(x < 1) x = n;
	if(x > n) x = 1;
	if(y < 1) y = m;
	if(y > m) y = 1;
	if(vis[x][y][d][num]) return;
	vis[x][y][d][num] = 1;
	if(s[x][y] == '@') exit((puts("YES"), 0));
	if(s[x][y] == '<') dfs(x, y - 1, 3, num);
	if(s[x][y] == '>') dfs(x, y + 1, 1, num);
	if(s[x][y] == '^') dfs(x - 1, y, 2, num);
	if(s[x][y] == 'v') dfs(x + 1, y, 0, num);
	if(s[x][y] == '_') {
		if(num) dfs(x, y - 1, 3, num);
		else dfs(x, y + 1, 1, num);
	}
	if(s[x][y] == '|') {
		if(num) dfs(x - 1, y, 2, num);
		else dfs(x + 1, y, 0, num);
	}
	if(s[x][y] == '.') dfs(x + dx[d], y + dy[d], d, num);
	if(s[x][y] == '?') for(int i = 0; i < 4; i++) dfs(x + dx[i], y + dy[i], i, num);
	if(s[x][y] == '+') dfs(x + dx[d], y + dy[d], d, (num + 1) % 16);
	if(s[x][y] == '-') dfs(x + dx[d], y + dy[d], d, (num + 15) % 16);
	if(isdigit(s[x][y])) dfs(x + dx[d], y + dy[d], d, s[x][y] ^ '0');
}
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	dfs(1, 1, 1, 0);
	puts("NO");
}
