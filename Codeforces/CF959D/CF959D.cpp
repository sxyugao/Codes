#include <set>
#include <vector>
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
const int MAXN = 1000000;
set<int>s;
bool p[MAXN + 5], vis[MAXN + 5];
vector<int>d[MAXN + 5];
int main(){
	for(int i = 2; i <= MAXN; i++) {
		s.insert(i);
		if(!p[i]) {
			for(int j = 1; i * j <= MAXN; j++) {
				d[i * j].push_back(i);
				p[i * j] = 1;
			}
		}
	}
	bool f = 1;
	for(int n = read(); n; n--) {
		int x = read();
		int ans = *s.begin();
		if(f) {
			ans = *s.lower_bound(x);
			if(ans != x) f = 0;
		}
		printf("%d ", ans);
		for(int i = 0; i < (int)d[ans].size(); i++) {
			for(int j = d[ans][i]; j <= MAXN; j += d[ans][i]) {
				if(!vis[j]) {
					s.erase(j);
					vis[j] = 1;
				}
			}
		}
	}
}
