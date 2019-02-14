#include <vector>
#include <cstdio>
#include <iostream>
using namespace std;
typedef long long LL;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 6e6 + 5;
vector<int>v;
int rt, tot, trie[MAXN][2];
void insert(int &rt, int x, int d){
	if(!rt) rt = ++tot, trie[rt][0] = trie[rt][1] = 0;
	if(d < 0) return;
	insert(trie[rt][x >> d & 1], x, d - 1);
}
int query(int rt, int x, int d){
	if(d < 0) return 0;
	bool p = x >> d & 1;
	if(trie[rt][p]) return query(trie[rt][p], x, d - 1);
	return query(trie[rt][p ^ 1], x, d - 1) + (1 << d);
}
LL solve(vector<int>v, int d){
	if(!v.size() || d < 0) return 0;
	vector<int>a[2];
	for(int x : v) a[x >> d & 1].push_back(x);
	LL ans = solve(a[0], d - 1) + solve(a[1], d - 1);
	if(a[0].size() && a[1].size()) {
		rt = tot = 0;
		for(int x : a[0]) insert(rt, x, d);
		int Min = 0x7fffffff;
		for(int x : a[1]) Min = min(Min, query(rt, x, d));
		ans += Min;
	}
	return ans;
}
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) v.push_back(read());
	printf("%lld\n", solve(v, 29));
}
