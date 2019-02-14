#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	if((n - 2) % 3) return printf("1 1 %d", n - 2), 0;
	if((n - 3) % 3) return printf("1 2 %d", n - 3), 0;
	printf("2 2 %d", n - 4);
}
