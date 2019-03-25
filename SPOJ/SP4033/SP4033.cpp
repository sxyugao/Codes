#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 10005;
int n, tot, trie[MAXN * 10][10], cnt[MAXN * 10];
char s[MAXN][10];
void init(){
	for(int i = 0; i <= tot; i++) {
		memset(trie[i], 0, sizeof(trie[i]));
		cnt[i] = 0;
	}
	tot = 0;
}
void insert(char *s){
	int rt = 0;
	for(int i = 0; s[i]; i++) {
		int p = s[i] ^ '0';
		if(!trie[rt][p]) trie[rt][p] = ++tot;
		rt = trie[rt][p];
		cnt[rt]++;
	}
}
bool query(char *s){
	int rt = 0;
	for(int i = 0; s[i]; i++) {
		rt = trie[rt][s[i] ^ '0'];
		if(cnt[rt] == 1) return 0;
	}
	return 1;
}
int main(){
	int T; scanf("%d", &T);
	while(T--) {
		init();
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%s", s[i]);
			insert(s[i]);
		}
		bool f = 1;
		for(int i = 1; i <= n && f; i++)
			if(query(s[i])) f = 0;
		if(f) puts("YES");
		else puts("NO");
	}
}
