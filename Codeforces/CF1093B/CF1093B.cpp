#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
char s[1000];
int main(){
	int T;
	scanf("%d\n", &T);
	while(T--) {
		gets(s);
		int len = strlen(s);
		sort(s, s + len);
		if(s[len - 1] == s[0]) puts("-1");
		else puts(s);
	}
}
