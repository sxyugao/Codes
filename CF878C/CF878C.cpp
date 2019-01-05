#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int n, m;
struct Data {
	int siz, mx[10], mn[10];
	bool operator<(const Data &b) const {
		for(int i = 0; i < m; i++)
			if(mx[i] > b.mn[i]) return 1;
		return 0;
	}
	Data operator+(const Data &b) const {
		Data c;
		c.siz = siz + b.siz;
		for(int i = 0; i < m; i++) {
			c.mx[i] = max(mx[i], b.mx[i]);
			c.mn[i] = min(mn[i], b.mn[i]);
		}
		return c;
	}
	void input(){
		siz = 1;
		for(int i = 0; i < m; i++) mx[i] = mn[i] = read();
	}
};
typedef set<Data>::iterator iter;
set<Data>s;
Data x;
int main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		x.input();
		iter it = s.upper_bound(x);
		while(it != s.end() && x < *it && *it < x) {
			x = x + *it;
			s.erase(it++);
		}
		s.insert(x);
		printf("%d\n", s.begin()->siz);
	}
}
