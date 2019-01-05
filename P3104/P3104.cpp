#include <bits/stdc++.h>
using namespace std;
inline char _gc(){
	static char buf[1 << 14], *p1 = buf, *p2 = buf;
	return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 14, stdin), p1 == p2) ? EOF : *p1++;
}
#define gc c = _gc()
int read(){
	int x = 0, cnt1 = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') cnt1 = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * cnt1;
}
#undef gc
int n, opt, Ans[505];
int deg[505], cnt1[505], cnt2[505];
int main(){
	n = read() + 1;
	for(int i = 1; i <= n; i++) deg[i] = read();
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		memset(cnt1, 0, sizeof(cnt1));
		memset(cnt2, 0, sizeof(cnt2));
		for(int j = 1; j <= n; j++)
			if(i ^ j) cnt1[deg[j]]++;
		bool flag = 1;
		for(int j = n; j && flag; j--)
			while(cnt1[j]--) {
				int num = j;
				for(int k = j; k && flag; k--)
					if(cnt1[k] >= num) cnt1[k] -= num, cnt2[k - 1] += num, num = 0;
					else num -= cnt1[k], cnt2[k - 1] += cnt1[k], cnt1[k] = 0;
				if(num) flag = 0;
				for(int k = 0; k <= n; k++) cnt1[k] += cnt2[k], cnt2[k] = 0;
			}
		if(flag) Ans[++ans] = i;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= ans; i++) printf("%d\n", Ans[i]);
}
