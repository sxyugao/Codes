#include <cstdio>
#include <iostream>
using namespace std;
int n, x, a[3] = {0, 1, 2};
int main(){
	scanf("%d%d", &n, &x); n %= 6;
	for(int i = 1; i <= n; i++)
		if(i & 1) swap(a[0], a[1]);
		else swap(a[1], a[2]);
	printf("%d", a[x]);
}
