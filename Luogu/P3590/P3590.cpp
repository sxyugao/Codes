#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 1000005;
int n, sum[MAXN][3];
char s[MAXN];
bool check(int x, int y){
	int A = sum[y][0] - sum[x - 1][0];
	int B = sum[y][1] - sum[x - 1][1];
	int C = sum[y][2] - sum[x - 1][2];
	return !((A == B && A && B) || (A == C && A && C) || (B == C && B && C));
}
int main(){
	scanf("%d\n", &n);
	gets(s);
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < 3; j++) sum[i][j] = sum[i - 1][j];
		switch (s[i - 1]) {
		case 'B': sum[i][0]++;
			break;
		case 'C': sum[i][1]++;
			break;
		case 'S': sum[i][2]++;
			break;
		}
	}
	int ans = 0;
	for(int i = 1; i <= n && i <= 3; i++)
		for(int j = i; j <= n; j++)
			if(check(i, j)) ans = max(ans, j - i + 1);
	for(int i = max(n - 2, 0); i <= n; i++)
		for(int j = 1; j <= i; j++)
			if(check(j, i)) ans = max(ans, i - j + 1);
	printf("%d", ans);
}
