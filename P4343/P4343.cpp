#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
#define gc c = getchar()
int read (){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int n, m, a[100005];
bool check(LL x){
	LL now = 0, cnt = 0;
	for(int i = 1; i <= n; i++) {
		now += a[i];
		if(now < 0) now = 0;
		if(now >= x) cnt++, now = 0;
	}
	return cnt >= m;
}
LL BinarySearch(LL l, LL r){
	LL ans = -1;
	while(l <= r) {
		LL mid = (l + r) >> 1;
		if(check(mid)) ans = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ans;
}
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	LL Max = BinarySearch(1, 1e18);
	if(Max < 0) return puts("-1"), 0;
	m++;
	LL Min = BinarySearch(1, 1e18) + 1;
	if(Min <= 0) Min = 1;
	if(Min > Max) return puts("-1"), 0;
	printf("%lld %lld", Min, Max);
}
