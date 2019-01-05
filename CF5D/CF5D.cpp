#include <cmath>
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
const double eps = 1e-12;
bool check(double a, double v0, double v, double dis, double lim){
	double x = (v * v - v0 * v0) / 2 / a;
	dis -= x;
	v0 = v;
	v = sqrt(max(-2 * a * dis + v0 * v0, 0.0));
	return v <= lim;
}
int main(){
	double a = read(), vm = read(), L = read(), d = read(), ans;
	double lim = min((double)read(), vm);
	double t = lim / a;
	double x = 0.5 * a * t * t;
	if(x >= d) {
		t = vm / a;
		x = 0.5 * a * t * t;
		if(x >= L) ans = sqrt(2 * L / a);
		else ans = t + (L - x) / vm;
	}else{
		if(vm > lim) {
			double l = lim / eps, r = vm / eps, mm = lim / eps;
			while(l <= r) {
				double mid = (l + r) / 2;
				if(check(a, lim, mid * eps, d - x, lim)) l = mid + 1, mm = mid;
				else r = mid - 1;
			}
			mm *= eps;
			t = mm / a;
			double t1 = abs(lim - mm) / a;
			ans = t + t1 + max(0.0, (d - 0.5 * a * t * t - (mm * t1 - 0.5 * a * t1 * t1))) / mm;
		}else ans = t + (d - x) / vm;
		double v = sqrt(lim * lim + 2 * a * (L - d));
		if(v <= vm) ans += (v - lim) / a;
		else{
			x = (vm * vm - lim * lim) / 2 / a;
			ans += (L - d - x) / vm + (vm - lim) / a;
		}
	}
	printf("%.15lf", ans);
}
