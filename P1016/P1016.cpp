#include <queue>
#include <cstdio>
struct Gas {
	double v, cost;
};
std::deque<Gas>q;
int n;
double c, nc, D1, D2, p[10], d[10];
int main(){
	scanf("%lf%lf%lf%lf%d", &D1, &c, &D2, &p[0], &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lf%lf", d + i, p + i);
		if(d[i] - d[i - 1] > c * D2) return puts("No Solution"), 0;
	}
	d[n + 1] = D1;
	if(D1 - d[n] > c * D2) return puts("No Solution"), 0;
	q.push_back((Gas){c, p[0]});
	nc = c;
	double ans = p[0] * c;
	for(int i = 1; i <= n + 1; i++) {
		double need = (d[i] - d[i - 1]) / D2;
		while(!q.empty() && need > 0) {
			Gas use = q.front(); q.pop_front();
			if(use.v > need) {
				use.v -= need;
				nc -= need;
				q.push_front(use);
				break;
			}
			need -= use.v;
			nc -= use.v;
		}
		if(i == n + 1) {
			for(Gas use : q) ans -= use.v * use.cost;
			break;
		}
		while(!q.empty() && q.back().cost > p[i]) {
			nc -= q.back().v;
			ans -= q.back().v * q.back().cost;
			q.pop_back();
		}
		ans += (c - nc) * p[i];
		q.push_back((Gas){c - nc, p[i]});
		nc = c;
	}
	printf("%.2lf", ans);
}
