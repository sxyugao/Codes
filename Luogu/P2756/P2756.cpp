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
bool a[205][205], used[205];
int n, m, e, match[205];
bool dfs(int pos){
	for(int i = m + 1; i <= n; i++)
		if(a[pos][i] && !used[i]) {
			used[i] = 1;
			if(!match[i] || dfs(match[i])) {
				match[i] = pos;
				return 1;
			}
		}
	return 0;
}
int main(){
	m = read(), n = read();
	for(int x, y; x = read(), y = read(), ~x && ~y; a[x][y] = 1);
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		memset(used, 0, sizeof(used));
		if(dfs(i)) ans++;
	}
	if(!ans) return puts("No Solution!"), 0;
	printf("%d\n", ans);
	for(int i = m + 1; i <= n; i++)
		if(match[i]) printf("%d %d\n", i, match[i]);
}
