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
int main(){
	int n = read();
	double tot = 0, sum = 0;
	for(int i = 1; i <= n; i++) tot += read();
	for(int i = 1; i <= n; i++) sum += read();
	printf("%.6lf", (tot * 3 - sum * 2) / (tot - sum));
}
