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
const int MAXN = 5005;
int Abs(int x){
	return x < 0 ? -x : x;
}
int n, m, T, ans;
int a[MAXN];
struct Data {
	int b, c;
	bool operator<(const Data &other) const {
		return b < other.b;
	}
} b[MAXN];
int s[MAXN], f[MAXN][MAXN];
signed main(){
	n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	int tot = 0;
	for(int i = 1; i <= m; i++) {
		b[i].b = read(), b[i].c = read();
		tot += b[i].c;
	}
	if(tot < n) return puts("-1"), 0;
	sort(a + 1, a + n + 1);
	sort(b + 1, b + m + 1);
	memset(f, 0x3f, sizeof(f));
	f[0][0] = 0;
	for(int i = 1; i <= m; i++) {
		for(int j = 1; j <= n; j++) s[j] = s[j - 1] + Abs(a[j] - b[i].b);
		deque<int>q;
		for(int j = 0; j <= n; j++) {
			while(q.size() && q.front() + b[i].c < j) q.pop_front();
			while(q.size() && f[i - 1][q.back()] - s[q.back()] >= f[i - 1][j] - s[j]) q.pop_back();
			q.push_back(j);
			f[i][j] = f[i - 1][q.front()] + s[j] - s[q.front()];
		}
	}
	printf("%lld", f[m][n]);
}
