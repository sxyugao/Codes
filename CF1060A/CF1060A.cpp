#include <cstdio>
#include <iostream>
using namespace std;
char s[100];
int main(){
	int n, cnt = 0;
	scanf("%d%s", &n, s);
	for(int i = 0; i < n; i++)
		if(s[i] == '8') cnt++;
	printf("%d", min(cnt, n / 11));
}
