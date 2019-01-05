#include <vector>
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
const int MAXN = 100005;
vector<int>v[MAXN];
int f[MAXN];
int Find(int k){
	return f[k] == k ? k : Find(f[k]);
}
char opt[1];
int id[MAXN];
void merge(int x, int y){
	x = Find(x), y = Find(y);
	if(v[x].size() > v[y].size()) swap(x, y);
	f[x] = y;
	for(int num : v[x]) {
		vector<int>::iterator iter = lower_bound(v[y].begin(), v[y].end(), num);
		v[y].insert(iter, num);
	}
	vector<int>().swap(v[x]);
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) {
		int x = read();
		id[x] = i;
		v[i].push_back(x);
		f[i] = i;
	}
	while(m--) {
		int x = read(), y = read();
		merge(x, y);
	}
	for(m = read(); m; m--) {
		scanf("%s", opt);
		if(*opt == 'Q') {
			int x = read(), k = read();
			x = Find(x);
			if(k > (int)v[x].size()) puts("-1");
			else printf("%d\n", id[v[x][k - 1]]);
		}
		else merge(read(), read());
	}
}
