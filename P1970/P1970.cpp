#include <cstdio>
#include <iostream>
using namespace std;
int n, a[100005], f[100005][2];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	f[1][0] = f[1][1] = 1;
	for(int i = 2; i <= n; i++) {
		if(a[i] > a[i - 1]) f[i][0] = f[i - 1][1] + 1;
		else f[i][0] = f[i - 1][0];
		if(a[i] < a[i - 1]) f[i][1] = f[i - 1][0] + 1;
		else f[i][1] = f[i - 1][1];
	}
	printf("%d", max(f[n][0], f[n][1]));
}
