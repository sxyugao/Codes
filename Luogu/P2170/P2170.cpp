#include <bits/stdc++.h>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 20100;
int Abs(int x){
	return x < 0 ? -x : x;
}
int a[MAXN], fa[MAXN], siz[MAXN];
int Find(int x){
	return x == fa[x] ? x : fa[x] = Find(fa[x]);
}
bitset<MAXN>f;
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= k; i++) {
		int x = read(), y = read();
		fa[Find(x)] = Find(y);
	}
	for(int i = 1; i <= n; i++) siz[Find(i)]++;
	for(int i = 1; i <= n; i++) if(siz[i]) a[++*a] = siz[i];
	f[0] = 1;
	for(int i = 1; i <= *a; i++) f |= f << a[i];
	int ans = -1e9;
	for(int i = 0; i <= n; i++)
		if(f[i] && Abs(i - m) < Abs(ans - m)) ans = i;
	printf("%d", ans);
}
