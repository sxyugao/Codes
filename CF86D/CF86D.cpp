#include <cmath>
#include <cstdio>
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
int len, cnt[1000005], a[200005];
long long now;
struct Ask {
	int l, r, L, id;
	long long ans;
} ask[200005];
bool cmp(Ask a, Ask b){
	if(a.L != b.L) return a.L < b.L;
	if(a.L & 1) return a.r < b.r;
	return a.r > b.r;
}
bool _cmp(Ask a, Ask b){
	return a.id < b.id;
}
void add(int x){
	now -= 1LL * cnt[x] * cnt[x] * x;
	cnt[x]++;
	now += 1LL * cnt[x] * cnt[x] * x;
}
void del(int x){
	now -= 1LL * cnt[x] * cnt[x] * x;
	cnt[x]--;
	now += 1LL * cnt[x] * cnt[x] * x;
}
int main(){
	int n = read(), m = read(); len = sqrt(n);
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) {
		ask[i].l = read(), ask[i].r = read();
		ask[i].L = ask[i].l / len, ask[i].id = i;
	}
	sort(ask + 1, ask + m + 1, cmp);
	int l = 0, r = 0;
	for(int i = 1; i <= m; i++) {
		while(r > ask[i].r) del(a[r--]);
		while(l < ask[i].l) del(a[l++]);
		while(l > ask[i].l) add(a[--l]);
		while(r < ask[i].r) add(a[++r]);
		ask[i].ans = now;
	}
	sort(ask + 1, ask + m + 1, _cmp);
	for(int i = 1; i <= m; i++) printf("%lld\n", ask[i].ans);
}
