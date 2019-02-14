#include <cstdio>
#include <iostream>
using namespace std;
const int Max = 32768;
int f[Max + 5][5];
int main(){
	f[0][0] = 1;
	for(int i = 1; i * i <= Max; i++) {
		int x = i * i;
		for(int j = x; j <= Max; j++)
			for(int k = 1; k <= 4; k++)
				f[j][k] += f[j - x][k - 1];
	}
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		int ans = 0;
		for(int i = 1; i <= 4; i++) ans += f[n][i];
		printf("%d\n", ans);
	}
}
