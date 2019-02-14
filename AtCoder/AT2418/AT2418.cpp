#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char a[4005], b[4005];
int f[4005][4005];
int main(){
	scanf("%s%s", a + 1, b + 1);
	int lena = strlen(a + 1), lenb = strlen(b + 1), ans = 0;
	for(int i = 1; i <= lena; i++)
		for(int j = 1; j <= lenb; j++)
			if(a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
				if(f[i][j] > ans) ans = f[i][j];
			}
	printf("%d\n", ans);
}
