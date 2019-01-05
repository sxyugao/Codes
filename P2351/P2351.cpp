#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 1200000;
int n, f[MAXN], siz[MAXN], cnt[MAXN];
int num, g[MAXN];
inline void solve(const int &x){
	for(register int i = 2; i <= n && x != 1; i++) f[i] = ((f[i] + 19940105) % (i - 1) + i - 1) % (i - 1) + 1;
	memset(siz, 0, sizeof(siz));
	memset(cnt, 0, sizeof(cnt));
	for(register int i = n; i; i--) {
		siz[i]++;
		siz[f[i]] += siz[i];
		cnt[siz[i]]++;
	}
	for(register int i = 1; i <= num; i++) {
		int tot = 0;
		for(register int j = 1; j <= n / g[i]; j++) tot += cnt[g[i] * j];
		if(tot == n / g[i]) printf("%d\n", g[i]);
	}
}
int main(){
	n = read();
	for(register int i = 1; i <= n; i++)
		if(n % i == 0) g[++num] = i;
	for(register int i = 2; i <= n; i++) f[i] = read();
	for(register int i = 1; i <= 10; i++) {
		printf("Case #%d:\n", i);
		solve(i);
	}
}
