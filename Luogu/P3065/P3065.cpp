#include <bits/stdc++.h>
using namespace std;
const int MAXN = 30005;
bool can[MAXN], vis[30], a[30][30];
int n, tot, scc, dfn[30], low[30];
int top, ss[30];
char s[MAXN][30];
void dfs(int k){
	dfn[k] = low[k] = ++tot; vis[k] = 1; ss[++top] = k;
	for(int i = 0; i < 26; i++)
		if(a[k][i]) {
			if(!dfn[i]) {
				dfs(i);
				low[k] = min(low[k], low[i]);
			}else if(vis[i]) low[k] = min(low[k], dfn[i]);
		}
	if(low[k] == dfn[k]) {
		scc++;
		int u;
		do {
			u = ss[top--];
			vis[u] = 0;
		} while(k != u);
	}
}
int cnt, ed[MAXN * 20], trie[MAXN * 20][26];
bool check(char *s){
	int k = 0;
	for(int i = 0; s[i]; i++) {
		int nxt = s[i] - 'a';
		if(ed[k]) return 0;
		for(int j = 0; j < 26; j++)
			if(j ^ nxt && trie[k][j]) a[nxt][j] = 1;
		k = trie[k][nxt];
	}
	tot = scc = top = 0;
	memset(dfn, 0, sizeof(dfn));
	memset(low, 0, sizeof(low));
	memset(vis, 0, sizeof(vis));
	for(int i = 0; i < 26; i++)
		if(!dfn[i]) dfs(i);
	return scc == 26;
}
void insert(char *s){
	int k = 0;
	for(int i = 0; s[i]; i++) {
		int nxt = s[i] - 'a';
		if(!trie[k][nxt]) trie[k][nxt] = ++cnt;
		k = trie[k][nxt];
	}
	ed[k] = 1;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s[i]);
		insert(s[i]);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		memset(a, 0, sizeof(a));
		if(check(s[i])) {
			ans++;
			can[i] = 1;
		}
	}
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++)
		if(can[i]) puts(s[i]);
}
