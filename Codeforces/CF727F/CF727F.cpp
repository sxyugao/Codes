#include <set>
#include <cstdio>
#include <iostream>
#include <algorithm>
#define int long long
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
int a[800], b[800];
multiset<int>s;
typedef multiset<int>::iterator iter;
signed main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = n; i; i--) {
		if(a[i] < 0) s.insert(-a[i]);
		else{
			while(!s.empty() && a[i]) {
				if(a[i] >= *s.begin()) {
					a[i] -= *s.begin();
					s.erase(s.begin());
				}else{
					int x = *s.begin();
					s.erase(s.begin());
					s.insert(x - a[i]);
					a[i] = 0;
				}
			}
		}
	}
	if(!s.empty()) {
		iter it = --s.end();
		for(int i = n; b[i] = *it, 1; i--, it--)
			if(it == s.begin()) break;
	}
	for(int i = 1; i <= n; i++) b[i] += b[i - 1];
	while(m--) {
		int x = read();
		printf("%lld\n", n - (upper_bound(b + 1, b + n + 1, x) - b - 1));
	}
}
