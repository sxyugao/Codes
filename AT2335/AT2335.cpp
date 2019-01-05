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
const int MAXN = 1e5 + 5;
struct Data {
	int x, id;
	bool operator<(const Data &b) const {
		if(x != b.x) return x > b.x;
		return id < b.id;
	}
} a[MAXN];
long long ans[MAXN];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i].x = read(), a[i].id = i;
	sort(a + 1, a + n + 1);
	int j = 1;
	for(int i = 2; i <= n; i++) {
		while(a[i].x == a[i - 1].x) i++;
		ans[a[j].id] += 1LL * (a[j].x - a[i].x) * (i - 1);
		if(a[j].id < a[i].id) a[j].x = a[i].x;
		else j = i;
	}
	ans[a[j].id] += 1LL * a[j].x * n;
	for(int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
}
