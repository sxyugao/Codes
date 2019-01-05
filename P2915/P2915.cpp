#include <cstdio>
#include <iostream>
using namespace std;
int a[20];
long long f[1 << 20][20];
int Abs(int x){
	return x < 0 ? -x : x;
}
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	for(int i = 1; i <= n; i++) f[1 << (i - 1)][i] = 1;
	for(int p = 0; p < (1 << n); p++)
		for(int i = 1; i <= n; i++)
			if(p & (1 << (i - 1)))
				for(int j = 1; j <= n; j++)
					if(!(p & (1 << (j - 1))))
						if(Abs(a[i] - a[j]) > k)
							f[p | (1 << (j - 1))][j] += f[p][i];
	long long ans = 0;
	for(int i = 1; i <= n; i++) ans += f[(1 << n) - 1][i];
	printf("%lld", ans);
}
