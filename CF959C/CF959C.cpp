#include <cstdio>
int main(){
	int n;
	scanf("%d", &n);
	if(n <= 5) puts("-1");
	else{
		puts("1 2");
		puts("2 3");
		puts("2 4");
		for(int i = 5; i <= n; i++)
			printf("3 %d\n", i);
	}
	for(int i = 1; i < n; i++)
		printf("%d %d\n", i, i + 1);
}
