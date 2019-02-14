#include <cstdio>
#include <iostream>
using namespace std;
int n, a[1005];
int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	int Mxid = 0, Mn = 0;
	for(int i = 1; i <= n; i++) {
		if(a[i] > a[Mxid]) {
			Mn = a[Mxid];
			Mxid = i;
		}
		else if(a[i] > Mn) Mn = a[i];
	}
	printf("%d %d", Mxid, Mn);
}
