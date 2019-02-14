#include <queue>
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
priority_queue<int, vector<int>, less<int> >q1;
priority_queue<int, vector<int>, greater<int> >q2;
char opt[5];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) {
		q1.push(read());
		while(q1.size() > q2.size()) {
			q2.push(q1.top());
			q1.pop();
		}
		while(q1.size() && q2.size() && q1.top() > q2.top()) {
			int x = q2.top(); q2.pop();
			q2.push(q1.top()); q1.pop();
			q1.push(x);
		}
	}
	for(n = read(); n; n--) {
		scanf("%s", opt);
		if(*opt == 'a') {
			q1.push(read());
			while(q1.size() > q2.size()) {
				q2.push(q1.top());
				q1.pop();
			}
			while(q1.size() && q2.size() && q1.top() > q2.top()) {
				int x = q2.top(); q2.pop();
				q2.push(q1.top()); q1.pop();
				q1.push(x);
			}
		}
		else printf("%d\n", (q1.size() + q2.size()) & 1 ? q2.top() : q1.top());
	}
}
