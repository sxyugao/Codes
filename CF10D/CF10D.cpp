#include <cstdio>
#include <iostream>
using namespace std;
int len1, len2, a[505], b[505];
int g[505], f[505];
void print(int k){
	if(!k) return;
	print(g[k]);
	printf("%d ", b[k]);
}
int main(){
	scanf("%d", &len1);
	for(int i = 1; i <= len1; i++) scanf("%d", a + i);
	scanf("%d", &len2);
	for(int i = 1; i <= len2; i++) scanf("%d", b + i);
	for(int i = 1; i <= len1; i++) {
		int k = 0;
		for(int j = 1; j <= len2; j++) {
			if(a[i] == b[j]) {
				f[j] = f[k] + 1;
				g[j] = k;
			}
			if(a[i] > b[j] && f[k] < f[j]) k = j;
		}
	}
	int Mx = 0;
	for(int i = 1; i <= len2; i++)
		if(f[i] > f[Mx]) Mx = i;
	printf("%d\n", f[Mx]);
	print(Mx);
}
