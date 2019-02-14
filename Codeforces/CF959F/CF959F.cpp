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
const int P = 1e9 + 7;
bool vis[1 << 20];
int num, a[100005], b[1 << 20];
struct Ask {
	int l, x, id, ans;
} ask[100005];
bool cmp(Ask a, Ask b){
	return a.l < b.l;
}
bool _cmp(Ask a, Ask b){
	return a.id < b.id;
}
int main(){
	int n = read(), m = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= m; i++) ask[i].l = read(), ask[i].x = read(), ask[i].id = i;
	sort(ask + 1, ask + m + 1, cmp);
	vis[0] = 1;
	b[++num] = 0;
	int ans = 1, p = 1;
	for(int i = 1; i <= n; i++) {
		if(vis[a[i]]) ans = ans * 2 % P;
		else{
			for(int j = 1; j <= num; j++) {
				if(!vis[a[i] ^ b[j]]) b[++num] = a[i] ^ b[j];
				vis[a[i] ^ b[j]] = 1;
			}
		}
		while(i >= ask[p].l && p <= m) {
			if(vis[ask[p].x]) ask[p].ans = ans;
			else ask[p].ans = 0;
			p++;
		}
	}
	sort(ask + 1, ask + m + 1, _cmp);
	for(int i = 1; i <= m; i++) printf("%d\n", ask[i].ans);
}
