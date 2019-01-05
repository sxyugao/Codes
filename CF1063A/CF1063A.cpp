#include <cstdio>
char s[100000];
int n, cnt[26];
int main(){
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; i++) cnt[s[i] - 'a']++;
	for(int i = 0; i < 26; i++)
		while(cnt[i]--) putchar(i + 'a');
}
