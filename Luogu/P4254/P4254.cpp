#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 50005;
int n, x, num, tree[MAXN << 2];
char opt[20];
double k[MAXN << 1], b[MAXN << 1];
double f(int x, int p){
	return k[x] * (p - 1) + b[x];
}
void upd(int rt, int l, int r, int x){
	if(l == r) {
		if(f(x, l) > f(tree[rt], l)) tree[rt] = x;
		return;
	}
	int mid = (l + r) >> 1;
	if(k[tree[rt]] < k[x]) {
		if(f(x, mid) > f(tree[rt], mid)) {
			upd(rt << 1, l, mid, tree[rt]);
			tree[rt] = x;
		}
		else upd(rt << 1 | 1, mid + 1, r, x);
	}else{
		if(f(x, mid) > f(tree[rt], mid)) {
			upd(rt << 1 | 1, mid + 1, r, tree[rt]);
			tree[rt] = x;
		}else upd(rt << 1, l, mid, x);
	}
}
double query(int rt, int l, int r, int x){
	if(l == r) return f(tree[rt], l);
	int mid = (l + r) >> 1;
	if(x <= mid) return max(f(tree[rt], x), query(rt << 1, l, mid, x));
	else return max(f(tree[rt], x), query(rt << 1 | 1, mid + 1, r, x));
}
int main(){
	scanf("%d", &n);
	while(n--) {
		scanf("%s", opt);
		if(*opt == 'P') {
			num++;
			scanf("%lf%lf", &b[num], &k[num]);
			upd(1, 1, MAXN, num);
		}else{
			scanf("%d", &x);
			printf("%d\n", (int)(query(1, 1, MAXN, x) / 100));
		}
	}
}
