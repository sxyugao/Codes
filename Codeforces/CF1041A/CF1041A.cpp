#include <cstdio>
#include <algorithm>
int n, a[1005];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	std::sort(a + 1, a + n + 1);
	long long ans = 0;
	for(int i = 2; i <= n; i++) ans = ans + a[i] - a[i - 1] - 1;
	printf("%lld", ans);
}
