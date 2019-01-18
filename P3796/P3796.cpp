#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 200;
char s[MAXN][100];
int num, ans[MAXN];
struct _AC {
	int tot, trie[MAXN * 100][26];
	int fail[MAXN * 100], vis[MAXN * 100];
	void init(){
		for(int i = 0; i <= tot; i++) {
			memset(trie[i], 0, sizeof(trie[i]));
			fail[i] = 0;
			vis[i] = 0;
		}
		tot = num = 0;
		memset(ans, 0, sizeof(ans));
	}
	void insert(char *s, int id){
		int rt = 0;
		for(int i = 0; s[i]; i++) {
			int p = s[i] - 'a';
			if(!trie[rt][p]) trie[rt][p] = ++tot;
			rt = trie[rt][p];
		}
		vis[rt] = id;
	}
	void build(){
		queue<int>q;
		for(int i = 0; i < 26; i++)
			if(trie[0][i]) q.push(trie[0][i]);
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int i = 0; i < 26; i++) {
				if(trie[x][i]) q.push(trie[x][i]), fail[trie[x][i]] = trie[fail[x]][i];
				else trie[x][i] = trie[fail[x]][i];
			}
		}
	}
	void find(char *s){
		int rt = 0;
		for(int i = 0; s[i]; i++) {
			rt = trie[rt][s[i] - 'a'];
			for(int j = rt; j; j = fail[j])
				if(vis[j]) {
					ans[vis[j]]++;
					if(j) num = max(num, ans[vis[j]]);
				}
		}
	}
} AC;
int main(){
	int n;
	while(~scanf("%d", &n) && n) {
		AC.init();
		for(int i = 1; i <= n; i++) {
			scanf("%s", s[i]);
			AC.insert(s[i], i);
		}
		AC.build();
		scanf("%s", s[0]);
		AC.find(s[0]);
		printf("%d\n", num);
		for(int i = 1; i <= n; i++)
			if(ans[i] == num) puts(s[i]);
	}
}