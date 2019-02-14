#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
char s[500];
int main(){
	int n;
	scanf("%d%s", &n, s);
	int ans = 1;
	sort(s, s + n);
	puts(s);
	while(next_permutation(s, s + n)) {
		ans++;
		puts(s);
	}
	printf("%d", ans);
}
