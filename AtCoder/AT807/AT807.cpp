#include <cstdio>
#include <iostream>
using namespace std;
int n;
int main(){
	scanf("%d", &n);
	for(int i = 2; i * i <= n; i++)
		if(n % i == 0) return puts("NO"), 0;
	puts("YES");
}
