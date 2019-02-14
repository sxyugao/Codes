#include <cstdio>
#include <iostream>
using namespace std;
int n, num, a[2005];
int gcd(int x, int y){
	return y ? gcd(y, x % y) : x;
}
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if(a[i] == 1) num++;
	}
	int GCD = a[1];
	for(int i = 2; i <= n; i++) GCD = gcd(GCD, a[i]);
	if(GCD != 1) return puts("-1"), 0;
	int ans = 1e9;
	for(int i = 1; i <= n; i++) {
		GCD = a[i];
		if(GCD == 1) ans = min(ans, n);
		for(int j = i + 1; j <= n; j++) {
			GCD = gcd(GCD, a[j]);
			if(GCD == 1) {
				ans = min(ans, n + j - i - 1);
				break;
			}
		}
	}
	printf("%d", ans - num);
}
