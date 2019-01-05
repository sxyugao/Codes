#include <cstdio>
#include <iostream>
using namespace std;
long long f[25] = {0, 0, 1};
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 3; i <= n; i++) f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
	printf("%lld", f[n]);
}
