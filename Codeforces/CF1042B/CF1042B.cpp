#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int n, x, f[1005];
char s[10];
int main(){
	scanf("%d", &n);
	memset(f, 0x3f, sizeof(f));
	f[0] = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d%s", &x, s);
		int v = 0;
		for(int j = 0; s[j]; j++) v |= 1 << (s[j] - 'A');
		for(int j = 7; ~j; j--) f[j | v] = min(f[j | v], f[j] + x);
	}
	printf("%d", f[7] > 1e9 ? -1 : f[7]);
}
