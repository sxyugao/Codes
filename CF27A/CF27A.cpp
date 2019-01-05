#include <cstdio>
#include <iostream>
using namespace std;
bool f[3010];
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		f[x] = 1;
	}
	for(int i = 1; i <= 3005; i++)
		if(!f[i]) {
			printf("%d", i);
			break;
		}
}
