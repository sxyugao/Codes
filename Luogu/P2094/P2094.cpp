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
priority_queue<int>q;
int main(){
	int n = read(), k = read();
	for(int i = 1; i <= n; i++) q.push(read());
	while(q.size() > 1) {
		int x = q.top(); q.pop();
		int y = q.top(); q.pop();
		q.push((x + y) / k);
	}
	printf("%d", q.top());
}
