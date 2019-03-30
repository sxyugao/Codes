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
const int MAXN = 1e5 + 5;
int nedge, head[MAXN];
struct Edge {
	int to, nxt, w;
} edge[MAXN << 1];
void add(int x, int y){
	edge[++nedge].to = y;
	edge[nedge].nxt = x;
	head[x] = nedge;
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= m; i++) {
		int x = read(), y = read();
		add(x, y), add(y, x);
	}
}
