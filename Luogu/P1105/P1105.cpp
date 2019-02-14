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
struct Data {
	int h, l, r;
} a[1005];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i].h = read(), a[i].l = read(), a[i].r = read();
	for(int i = 1; i <= n; i++) {
		int ans = 0, h = 0;
		for(int j = 1; j <= n; j++)
			if(a[j].l < a[i].l && a[i].l < a[j].r && a[j].h > h && a[j].h < a[i].h) {
				h = a[j].h; ans = j;
			}
		printf("%d ", ans);
		ans = h = 0;
		for(int j = 1; j <= n; j++)
			if(a[j].l < a[i].r && a[i].r < a[j].r && a[j].h > h && a[j].h < a[i].h) {
				h = a[j].h; ans = j;
			}
		printf("%d\n", ans);
	}
}
