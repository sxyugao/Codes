#include <bits/stdc++.h>
using namespace std;
#define int long long
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 1e5;
int a[MAXN], b[MAXN];
vector<int>v[MAXN];
int Abs(int x){
	return x < 0 ? -x : x;
}
signed main(){
	read();
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int ans = 0;
	for(int i = 2; i <= n; i++) ans += Abs(a[i] - a[i - 1]);
	for(int i = 2; i <= n; i++) {
		if(a[i] != a[i - 1]) {
			v[a[i]].push_back(a[i - 1]);
			v[a[i - 1]].push_back(a[i]);
		}
	}
	int t = ans;
	int tmp;
	for(int i = 1; i <= MAXN; i++)
		if(v[i].size()) {
			tmp = t;
			sort(v[i].begin(), v[i].end());
			int mid = v[i][v[i].size() / 2];
			for(int j = 0; j < (int)v[i].size(); j++)
				tmp += Abs(mid - v[i][j]) - Abs(i - v[i][j]);
			ans = min(ans, tmp);
		}
	printf("%lld", ans);
}
