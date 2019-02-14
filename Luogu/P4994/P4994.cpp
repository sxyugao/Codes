#include <cstdio>
#include <iostream>
using namespace std;
int n, a, b, c, P;
int main(){
	scanf("%d", &P);
	a = 1, b = 1, n = 1;
	while(!(a == 0 && b == 1)) {
		n++;
		c = (a + b) % P;
		a = b; b = c;
	}
	printf("%d", n);
}
