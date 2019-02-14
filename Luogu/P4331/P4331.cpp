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
int Abs(int x){
	return x < 0 ? -x : x;
}
const int MAXN = 1000005;
int a[MAXN];
struct Data {
	Data(){
		l = r = w = 0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
	}
	Data(int L, int R, int W, int x){
		l = L, r = R;
		w = W;
		len = r - l + 1;
		q2.push(x);
		while(!q1.empty()) q2.pop();
	}
	int w, l, r, len;
	priority_queue<int, vector<int>, less<int> >q1;
	priority_queue<int, vector<int>, greater<int> >q2;
} s[MAXN];
inline void merge(Data &a, Data &b){
	if(a.len < b.len) swap(a, b);
	a.len += b.len;
	a.l = min(a.l, b.l);
	a.r = max(a.r, b.r);
	while(!b.q1.empty()) {
		a.q1.push(b.q1.top());
		b.q1.pop();
	}
	while(!b.q2.empty()) {
		a.q1.push(b.q2.top());
		b.q2.pop();
	}
	while(a.q1.size() > a.q2.size()) {
		a.q2.push(a.q1.top());
		a.q1.pop();
	}
	while(a.q1.size() && a.q2.size() && a.q1.top() > a.q2.top()) {
		int x = a.q2.top(); a.q2.pop();
		a.q2.push(a.q1.top()); a.q1.pop();
		a.q1.push(x);
	}
	a.w = a.q2.top();
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read() - i;
	int top = 0;
	for(int i = 1; i <= n; i++) {
		s[++top] = Data(i, i, a[i], a[i]);
		while(top > 1 && s[top - 1].w > s[top].w) {
			top--;
			merge(s[top], s[top + 1]);
		}
	}
	int now = 1;
	long long ans = 0;
	for(int i = 1; i <= top; i++)
		while(now <= s[i].r) ans += Abs(a[now] - s[i].w), now++;
	printf("%lld\n", ans);
	now = 1;
	for(int i = 1; i <= top; i++)
		while(now <= s[i].r) printf("%d ", s[i].w + now), now++;
}
