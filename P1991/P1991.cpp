#include <cmath>
#include <cstdio>
#include <iostream>
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
int num, x[505], y[505], f[505];
int Find(int k){
	return f[k] == k ? k : f[k] = Find(f[k]);
}
struct Edge {
	int x, y, z;
	bool operator<(const Edge &b) const {
		return z < b.z;
	}
} edge[250005];
int sqr(int x){
	return x * x;
}
int main(){
	int m = read(), n = read();
	for(int i = 1; i <= n; i++) x[i] = read(), y[i] = read();
	for(int i = 1; i <= n; i++)
		for(int j = i + 1; j <= n; j++) {
			num++;
			edge[num].x = i;
			edge[num].y = j;
			edge[num].z = sqr(x[i] - x[j]) + sqr(y[i] - y[j]);
		}
	sort(edge + 1, edge + num + 1);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= num; i++) {
		int x = Find(edge[i].x), y = Find(edge[i].y);
		if(x != y) {
			n--;
			f[x] = y;
		}
		if(n == m) return printf("%.2lf", sqrt(edge[i].z)), 0;
	}
}
