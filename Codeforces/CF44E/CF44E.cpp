#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int k, a, b;
char s[205];
int main(){
	scanf("%d%d%d%s", &k, &a, &b, s);
	int len = strlen(s);
	if(a * k > len || b * k < len) return puts("No solution"), 0;
	int p = 0, r = len - k * a;
	while(k--) {
		int cur = min(b, a + r);
		r -= cur - a;
		for(int i = 0; i < cur; i++, p++) putchar(s[p]);
		puts("");
	}
}
