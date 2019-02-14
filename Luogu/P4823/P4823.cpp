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
struct P {
	int a, b;
	bool operator<(const P &other) const {
		return a + b < other.a + other.b;
	}
	void input(){
		a = read(), b = read();
	}
} p[2005];
int f[2005];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) p[i].input();
	sort(p + 1, p + n + 1);
	int h = read();
	for(int i = 1; i <= n; i++) f[0] += p[i].a;
	for(int i = 1; i <= n; i++) f[i] = -1e9;
	for(int i = 1; i <= n; i++)
		for(int j = i; j; j--)
			if(f[j - 1] + p[i].b >= h) f[j] = max(f[j], f[j - 1] - p[i].a);
	for(int i = n; ~i; i--)
		if(f[i] >= 0) return printf("%d", i), 0;
}
