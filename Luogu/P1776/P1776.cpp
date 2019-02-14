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
struct Data {
	int x, num;
};
deque<Data>q;
int f[40005];
int main(){
	int n = read(), m = read(), ans = 0;
	for(int i = 1; i <= n; i++) {
		int v = read(), w = read(), c = read();
		if(!w) {
			ans += v * c;
			continue;
		}
		c = min(c, m / w);
		for(int d = 0; d < w; d++) {
			while(!q.empty()) q.pop_front();
			int k = (m - d) / w;
			for(int j = 0; j <= k; j++) {
				while(!q.empty() && f[d + j * w] - j * v >= q.back().x) q.pop_back();
				Data New;
				New.num = j;
				New.x = f[d + j * w] - j * v;
				q.push_back(New);
				while(!q.empty() && q.front().num < j - c) q.pop_front();
				f[d + j * w] = max(f[d + j * w], q.front().x + j * v);
			}
		}
	}
	printf("%d", ans + f[m]);
}
