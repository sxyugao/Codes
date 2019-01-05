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
int num, S, T;
double a[500][500];
struct Point {
	int x, y;
} p[500];
int sqr(int x){
	return x * x;
}
double Dist(double x1, double y1, double x2, double y2, int cost){
	return sqrt(sqr(x1 - x2) + sqr(y1 - y2)) * cost;
}
double spfa(int s, int t){
	static double d[500];
	static bool vis[500];
	memset(vis, 0, sizeof(vis));
	for(int i = 1; i <= num; i++) d[i] = 1e9;
	d[s] = 0;
	queue<int>q;
	q.push(s);
	vis[s] = 1;
	while(!q.empty()) {
		int x = q.front(); q.pop(); vis[x] = 0;
		for(int y = 1; y <= num; y++)
			if(d[x] + a[x][y] < d[y]) {
				d[y] = d[x] + a[x][y];
				if(!vis[y]) {
					q.push(y);
					vis[y] = 1;
				}
			}
	}
	double ans = 1e9;
	for(int i = t - 3; i <= t; i++) ans = min(ans, d[i]);
	return ans;
}
int main(){
	for(int Case = read(); Case; Case--) {
		num = 0;
		memset(p, 0, sizeof(p));
		for(int i = 1; i <= 450; i++)
			for(int j = 1; j <= 450; j++)
				a[i][j] = 1e9;
		int n = read(), cost_fly = read(), s = read(), t = read();
		for(int i = 1; i <= n; i++) {
			int X1 = read(), Y1 = read(), X2 = read(), Y2 = read(), X3 = read(), Y3 = read(), cost = read(), X4, Y4;
			double nx, ny, mx, my, qx, qy;
			double l1 = Dist(X1, Y1, X2, Y2, 1);
			double l2 = Dist(X1, Y1, X3, Y3, 1);
			double l3 = Dist(X2, Y2, X3, Y3, 1);
			double l = max(l1, max(l2, l3));
			if(l1 == l) nx = X1, ny = Y1, mx = X2, my = Y2, qx = X3, qy = Y3;
			if(l2 == l) nx = X1, ny = Y1, mx = X3, my = Y3, qx = X2, qy = Y2;
			if(l3 == l) nx = X2, ny = Y2, mx = X3, my = Y3, qx = X1, qy = Y1;
			double midx = (nx + mx) / 2, midy = (ny + my) / 2;
			X4 = 2 * midx - qx; Y4 = 2 * midy - qy;
			p[++num].x = X1, p[num].y = Y1;
			p[++num].x = X2, p[num].y = Y2;
			p[++num].x = X3, p[num].y = Y3;
			p[++num].x = X4, p[num].y = Y4;
			for(int j = num - 3; j <= num; j++)
				for(int k = num - 3; k <= num; k++)
					a[j][k] = Dist(p[j].x, p[j].y, p[k].x, p[k].y, cost);
			for(int j = num - 3; j <= num; j++)
				for(int k = 1; k <= num - 4; k++)
					a[j][k] = a[k][j] = Dist(p[j].x, p[j].y, p[k].x, p[k].y, cost_fly);
			if(i == s) S = num;
			if(i == t) T = num;
		}
		double ans = 1e9;
		for(int i = S - 3; i <= S; i++) ans = min(spfa(i, T), ans);
		printf("%.1lf\n", ans);
	}
}
