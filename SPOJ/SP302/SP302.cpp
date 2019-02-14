#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	int T, n;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		printf("TERM %d IS ", n);
		int i = 1;
		while(i + 1 <= n) {
			n -= i;
			i++;
		}
		if(i & 1) printf("%d/%d\n", i + 1 - n, n);
		else printf("%d/%d\n", n, i + 1 - n);
	}
}
