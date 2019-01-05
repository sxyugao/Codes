#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int MAXN = 1e6 + 5;
int f[MAXN];
int top, s[MAXN];
char str[MAXN];
int main(){
	scanf("%s", str + 1);
	int n = strlen(str + 1);
	for(int i = 1; i <= n; i++)
		if(str[i] == '(') s[++top] = i;
		else f[i] = top ? i - s[top--] + 1 : 0;
	for(int i = 1; i <= n; i++)
		if(i - f[i] >= 0 && f[i - f[i]]) f[i] += f[i - f[i]];
	int ans = 0, cnt = 1;
	for(int i = 1; i <= n; i++)
		if(f[i]) {
			if(f[i] == ans) cnt++;
			if(f[i] > ans) ans = f[i], cnt = 1;
		}
	printf("%d %d", ans, cnt);
}
