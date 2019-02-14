#include <cstdio>
int main(){
	double n;
	scanf("%lf", &n);
	printf("%.10lf", n * (n + 1) / (4 * n - 2));
}
