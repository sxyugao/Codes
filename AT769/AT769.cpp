#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[105][105];
int main(){
	int n, ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
	int m = strlen(s[1] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(s[i][j] == 'x') ans++;
			if(s[i][j] == 'o' && s[i - 1][j] != 'o') ans++;
		}
	printf("%d", ans);
}
