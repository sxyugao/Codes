#include <vector>
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
const int MAXN = 2e5 + 5;
vector<int>v[MAXN];
bool vis[MAXN];
int row[MAXN], ln[MAXN];
void dfs(int x, int col){
	if(vis[x]) return;
	vis[x] = col;
	for(int i = 0; i < (int)v[x].size(); i++)
		dfs(v[x][i], col ^ 1);
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) {
		int x = read(), y = read();
		if(row[x]) {
			v[row[x]].push_back(i);
			v[i].push_back(row[x]);
			row[x] = 0;
		}else row[x] = i;
		if(ln[y]) {
			v[ln[y]].push_back(i);
			v[i].push_back(ln[y]);
			ln[y] = 0;
		}else ln[y] = i;
	}
	for(int i = 1; i <= n; i++) {
		dfs(i, 0);
		putchar(vis[i] ? 'r' : 'b');
	}
}
