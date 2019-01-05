#include <cstdio>
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
const int MAXN = 200005;
int n, h, l[MAXN], r[MAXN];
long long v1[MAXN], v2[MAXN];
bool check(int l, int r){
	return v1[r] - v1[l] < h;
}
int main(){
	n = read(), h = read();
	for(int i = 1; i <= n; i++) l[i] = read(), r[i] = read();
	v1[1] = 0;
	v2[1] = r[1] - l[1];
	for(int i = 2; i <= n; i++) {
		v1[i] = v1[i - 1] + l[i] - r[i - 1];
		v2[i] = v2[i - 1] + r[i] - l[i];
	}
	long long ans = 0;
	for(int i = 1; i <= n; i++) {
		int l = i, r = n, j;
		while(l <= r) {
			int mid = (l + r) >> 1;
			if(check(i, mid)) j = mid, l = mid + 1;
			else r = mid - 1;
		}
		ans = max(ans, h + v2[j] - v2[i - 1]);
	}
	printf("%lld", ans);
}
