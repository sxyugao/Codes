#include <cctype>
#include <cstdio>
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
int n, m, d, Ans[200005];
pair<int, int>a[200005];
bool check(int ans){
	for(int i = ans + 1; i <= n; i++)
		if(a[i].first - a[i - ans].first <= d) return 0;
	return 1;
}
int main(){
	n = read(), m = read(), d = read();
	for(int i = 1; i <= n; i++) a[i] = make_pair(read(), i);
	sort(a + 1, a + n + 1);
	int l = 1, r = n, ans = 0;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(check(mid)) ans = mid, r = mid - 1;
		else l = mid + 1;
	}
	for(int i = 1; i <= n; i++)
		Ans[a[i].second] = i % ans + 1;
	printf("%d\n", ans);
	for(int i = 1; i <= n; i++) printf("%d ", Ans[i]);
}
