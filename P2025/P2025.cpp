#include <cstdio>
int n, a, lst, ans;
int main(){
	scanf("%d", &n);
	while(n--) {
		scanf("%d", &a);
		if(lst < a) ans += a - lst;
		lst = a;
	}
	printf("%d", ans);
}
