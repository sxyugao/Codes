#include <queue>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int l, n, m;
int a[100005], b[100005];
LL f[100005], g[100005];
struct Data {
	Data(){
	}
	Data(int D, LL Now){
		d = D, now = Now;
	}
	int d;
	LL now;
	bool operator<(const Data &other) const {
		if(now != other.now) return now > other.now;
		return d > other.d;
	}
};
priority_queue<Data>q;
int main(){
	l = read(), n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) b[i] = read();
	for(int i = 1; i <= n; i++) q.push(Data(a[i], a[i]));
	for(int i = 1; i <= l; i++) {
		Data x = q.top(); q.pop();
		f[i] = x.now;
		x.now += x.d;
		q.push(x);
	}
	while(!q.empty()) q.pop();
	for(int i = 1; i <= m; i++) q.push(Data(b[i], b[i]));
	for(int i = 1; i <= l; i++) {
		Data x = q.top(); q.pop();
		g[i] = x.now;
		x.now += x.d;
		q.push(x);
	}
	LL ans = 0;
	for(int i = 1; i <= l; i++) ans = max(ans, f[i] + g[l - i + 1]);
	printf("%lld %lld", f[l], ans);
}
