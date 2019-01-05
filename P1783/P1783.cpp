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
const int MAXN = 1e6 + 5;
const double eps = 1e-4;
double sqr(long long x){
	return x * x;
}
int n, num, len;
struct Data {
	int x, y;
	double d;
	bool operator<(const Data &b) const {
		return d < b.d;
	}
} a[MAXN];
int x[MAXN], y[MAXN];
int f[MAXN];
int Find(int x){
	return f[x] = f[x] == x ? x : Find(f[x]);
}
bool check(double k){
	for(int i = 1; i <= n; i++) f[i] = i;
	int i = 1;
	while(a[i].d <= 2 * k && i <= num) {
		int X = Find(a[i].x), Y = Find(a[i].y);
		if(X != Y) f[X] = Y;
		i++;
	}
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			if(Find(i) == Find(j) && x[i] - k < 0 && x[j] + k > len)
				return 1;
	return 0;
}
int main(){
	len = read(), n = read();
	for(int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	for(int i = 1; i <= n; i++)
		for(int j = i; j <= n; j++) {
			a[++num].x = i;
			a[num].y = j;
			a[num].d = sqrt(sqr(x[i] - x[j]) + sqr(y[i] - y[j]));
		}
	sort(a + 1, a + num + 1);
	double l = 0, r = 10000000, ans = 0;
	while(l + eps <= r) {
		double mid = (l + r) / 2;
		if(check(mid)) ans = mid, r = mid - eps;
		else l = mid + eps;
	}
	printf("%.2lf", ans);
}
