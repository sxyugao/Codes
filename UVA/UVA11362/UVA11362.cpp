#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int T, n, cnt, trie[100100][20];
char s[10100][20];
void insert(char *s){
	int rt = 0;
	for(int i = 0; s[i]; i++) {
		int p = s[i] - '0';
		if(!trie[rt][p]) trie[rt][p] = ++cnt;
		rt = trie[rt][p];
	}
}
bool Find(char *s){
	int rt = 0;
	for(int i = 0; s[i]; i++) rt = trie[rt][s[i] - '0'];
	for(int i = 0; i <= 9; i++)
		if(trie[rt][i]) return 1;
	return 0;
}
int main(){
	scanf("%d", &T);
	while(T--) {
		memset(trie, 0, sizeof(trie));
		scanf("%d", &n);
		cnt = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%s", s[i]);
			insert(s[i]);
		}
		bool f = 0;
		for(int i = 1; i <= n; i++)
			if(Find(s[i])) {
				f = 1;
				puts("NO");
				break;
			}
		if(!f) puts("YES");
	}
}
