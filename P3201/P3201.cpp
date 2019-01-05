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
int a[100005], col[1000005];
set<int>s[1000005];
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		a[i] = read();
		s[a[i]].insert(i);
		col[a[i]] = a[i];
	}
	int ans = 1;
	for(int i = 2; i <= n; i++)
		if(a[i] != a[i - 1]) ans++;
	while(m--) {
		int opt = read();
		if(opt == 1) {
			int X = read(), Y = read();
			if(X == Y) continue;
			if(s[col[X]].size() > s[col[Y]].size())
				swap(col[X], col[Y]);
			X = col[X], Y = col[Y];
			for(int pos : s[X]) {
				if(a[pos - 1] == Y) ans--;
				if(a[pos + 1] == Y) ans--;
				s[Y].insert(pos);
			}
			for(int pos : s[X]) a[pos] = Y;
			s[X].clear();
		}else printf("%d\n", ans);
	}
}
