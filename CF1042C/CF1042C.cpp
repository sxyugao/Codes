#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 200005;
int n, a[MAXN];
bool used[MAXN];
int main(){
	scanf("%d", &n);
	a[0] = -0x3fffffff;
	int pos = 0, cnt0 = 0, cntf = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if(a[i] < 0) {
			cntf++;
			if(a[i] > a[pos]) pos = i;
		}
		if(a[i] == 0) cnt0++;
	}
	int lst = 0;
	for(int i = 1; i <= n; i++)
		if(a[i] == 0 && !used[i]) {
			used[i] = 1;
			if(lst) printf("1 %d %d\n", lst, i);
			lst = i;
		}
	if(cntf & 1) {
		if(lst) printf("1 %d %d\n", pos, lst);
		else printf("2 %d\n", pos);
		used[pos] = 1;
	}
	if(cnt0 == n || cnt0 + (cntf == 1) == n) return 0;
	if(lst) {
		printf("2 %d\n", lst);
		used[lst] = 1;
	}
	lst = 0;
	for(int i = 1; i <= n; i++)
		if(!used[i]) {
			if(lst) printf("1 %d %d\n", lst, i);
			lst = i;
		}
}
