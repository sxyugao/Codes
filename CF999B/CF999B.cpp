#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[100];
int main(){
	int n;
	scanf("%d%s", &n, s);
	for(int i = 1; i <= n; i++)
		if(n % i == 0) reverse(s, s + i);
	puts(s);
}
