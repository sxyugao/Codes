#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
bool f[25005] = {1};
int a[100];
int main(){
	for(int T = read(); T; T--) {
		int n = read();
		for(int i = 0; i < n; i++) a[i] = read();
		sort(a, a + n);
		for(int i = 1; i <= *(a + n - 1); i++) f[i] = 0;
		int ans = 0;
		for(int i = 0; i < n; i++) {
			if(f[a[i]]) continue;
			ans++;
			for(int j = a[i]; j <= *(a + n - 1); j++)
				f[j] |= f[j - a[i]];
		}
		printf("%d\n", ans);
	}
}
