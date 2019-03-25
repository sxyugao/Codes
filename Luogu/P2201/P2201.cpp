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
const int MAXN = 1e6 + 5;
char opt[1];
struct Stack {
	int len, s[MAXN];
	void push(int x){
		s[++len] = x;
	}
	void pop(){
		len--;
	}
	int top(){
		return s[len];
	}
	int size(){
		return len;
	}
} s1, s2;
int ans[MAXN], sum[MAXN];
int main(){
	ans[0] = -0x7ffffff;
	for(int n = read(); n; n--) {
		scanf("%s", opt);
		if(*opt == 'I') {
			int x = read();
			s1.push(x);
			sum[s1.size()] = sum[s1.size() - 1] + x;
			ans[s1.size()] = max(ans[s1.size() - 1], sum[s1.size()]);
		}
		if(*opt == 'D') s1.pop();
		if(*opt == 'L') {
			s2.push(s1.top());
			s1.pop();
		}
		if(*opt == 'R') {
			int x = s2.top(); s2.pop();
			s1.push(x);
			sum[s1.size()] = sum[s1.size() - 1] + x;
			ans[s1.size()] = max(ans[s1.size() - 1], sum[s1.size()]);
		}
		if(*opt == 'Q') printf("%d\n", ans[read()]);
	}
}
