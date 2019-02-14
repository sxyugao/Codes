#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 5;
int n, a[MAXN];
struct Aho_Corasick_Automaton {
	char s[MAXN];
	int tot, trie[MAXN][26];
	int fail[MAXN], End[MAXN], siz[MAXN];
	void insert(int x){
		int rt = 0;
		gets(s);
		for(int i = 0; s[i]; i++) {
			int p = s[i] - 'a';
			if(!trie[rt][p]) trie[rt][p] = ++tot;
			rt = trie[rt][p];
			siz[rt]++;
		}
		End[x] = rt;
	}
	void build(){
		queue<int>q;
		for(int i = 0; i < 26; i++)
			if(trie[0][i]) q.push(trie[0][i]);
		while(!q.empty()) {
			int x = q.front(); q.pop(); a[++*a] = x;
			for(int i = 0; i < 26; i++)
				if(trie[x][i]) {
					q.push(trie[x][i]);
					fail[trie[x][i]] = trie[fail[x]][i];
				}else trie[x][i] = trie[fail[x]][i];
		}
	}
	void solve(){
		for(int i = *a; i; i--) siz[fail[a[i]]] += siz[a[i]];
		for(int i = 1; i <= n; i++) printf("%d\n", siz[End[i]]);
	}
} AC;
int main(){
	scanf("%d\n", &n);
	for(int i = 1; i <= n; i++) AC.insert(i);
	AC.build();
	AC.solve();
}
