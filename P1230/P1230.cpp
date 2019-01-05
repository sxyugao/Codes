#include <queue>
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
const int MAXN = 505;
struct Data {
	int x, d;
	bool operator<(const Data &b) const {
		return d < b.d;
	}
} a[MAXN];
priority_queue<int>q;
int main(){
	int m = read(), n = read(), sum = 0;
	for(int i = 1; i <= n; i++) a[i].d = read();
	for(int i = 1; i <= n; i++) sum += (a[i].x = read());
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if((int)q.size() < a[i].d) {
			q.push(-a[i].x);
			ans += a[i].x;
		}else{
			if(-q.top() < a[i].x) {
				ans += q.top(); q.pop();
				ans += a[i].x; q.push(-a[i].x);
			}
		}
	}
	printf("%d", max(0, m - sum + ans));
}
