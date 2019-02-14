#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 5;
struct Aho_Corasick_Automaton {
	int tot, trie[MAXN][26], cnt[MAXN], fail[MAXN];
	void insert(char *s){
		int rt = 0;
		for(int i = 0; s[i]; i++) {
			int p = s[i] - 'a';
			if(!trie[rt][p]) trie[rt][p] = ++tot;
			rt = trie[rt][p];
		}
		cnt[rt]++;
	}
	void build(){
		queue<int>q;
		for(int i = 0; i < 26; i++)
			if(trie[0][i]) {
				fail[trie[0][i]] = 0;
				q.push(trie[0][i]);
			}
		while(!q.empty()) {
			int x = q.front(); q.pop();
			for(int i = 0; i < 26; i++) {
				int y = trie[x][i];
				if(y) {
					fail[y] = trie[fail[x]][i];
					q.push(y);
				}else trie[x][i] = trie[fail[x]][i];
			}
		}
	}
	int query(char *s){
		int rt = 0, ans = 0;
		for(int i = 0; s[i]; i++) {
			rt = trie[rt][s[i] - 'a'];
			for(int j = rt; j && ~cnt[j]; j = fail[j]) {
				ans += cnt[j];
				cnt[j] = -1;
			}
		}
		return ans;
	}
} AC;
int n;
char s[MAXN];
int main(){
	scanf("%d", &n);
	while(n--) {
		scanf("%s", s);
		AC.insert(s);
	}
	AC.build();
	scanf("%s", s);
	printf("%d\n", AC.query(s));
}
