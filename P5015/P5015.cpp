#include <cstdio>
#include <iostream>
using namespace std;
char s[10];
int main(){
	gets(s);
	int ans = 0;
	for(int i = 0; s[i]; i++)
		if(!isspace(s[i])) ans++;
	printf("%d", ans);
}
