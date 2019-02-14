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
int n, a[1005], x[1005];
int ans, Ans[1005];
bool check(int pos, int delta){
	int num = x[pos];
	while(pos <= n) {
		if(x[pos] != num) return 0;
		pos += delta;
	}
	return 1;
}
int main(){
	n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) x[i] = a[i] - a[i - 1];
	for(int i = 1; i <= n; i++) {
		bool f = 1;
		for(int j = 1; j <= i && f; j++) f &= check(j, i);
		if(f) Ans[++ans] = i;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= ans; i++) printf("%d ", Ans[i]);
}
