#include <queue>
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
struct Time {
	int h, m;
	int operator-(const Time &b) const {
		return h * 60 + m - b.h * 60 - b.m;
	}
} Ts, Te;
struct Data {
	int num, x;
};
deque<Data>q;
int f[1005];
int main(){
	scanf("%d:%d %d:%d", &Ts.h, &Ts.m, &Te.h, &Te.m);
	int n = read(), m = Te - Ts;
	for(int i = 1; i <= n; i++) {
		int w = read(), v = read(), c = read();
		if(!c) c = 1e9;
		c = min(c, m / w);
		for(int d = 0; d < w; d++) {
			while(!q.empty()) q.pop_back();
			int k = (m - d) / w;
			for(int j = 0; j <= k; j++) {
				while(!q.empty() && f[d + j * w] - v * j >= q.back().x) q.pop_back();
				Data New;
				New.num = j;
				New.x = f[d + j * w] - v * j;
				q.push_back(New);
				while(!q.empty() && q.front().num < j - c) q.pop_front();
				f[d + j * w] = max(f[d + j * w], q.front().x + v * j);
			}
		}
	}
	printf("%d", f[m]);
}
