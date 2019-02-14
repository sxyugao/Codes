#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int P = 1e9 + 7;
int len1, len2, m, f[2][205][205][2];
char a[1005], b[205];
void Add(int &x, int y){
	x = x + y >= P ? x + y - P : x + y;
}
int main(){
	scanf("%d%d%d", &len1, &len2, &m);
	scanf("%s%s", a + 1, b + 1);
	f[0][0][0][0] = 1;
	for(int i = 1; i <= len1; i++) {
		int now = i & 1;
		int lst = now ^ 1;
		f[now][0][0][0] = 1;
		for(int j = 1; j <= min(i, len2); j++)
			for(int k = 1; k <= min(j, m); k++) {
				f[now][j][k][0] = f[now][j][k][1] = 0;
				Add(f[now][j][k][0], f[lst][j][k][1]);
				Add(f[now][j][k][0], f[lst][j][k][0]);
				if(a[i] == b[j]) {
					Add(f[now][j][k][1], f[lst][j - 1][k][1]);
					Add(f[now][j][k][1], f[lst][j - 1][k - 1][0]);
					Add(f[now][j][k][1], f[lst][j - 1][k - 1][1]);
				}
			}
	}
	int now = len1 & 1;
	printf("%d", (f[now][len2][m][0] + f[now][len2][m][1]) % P);
}
