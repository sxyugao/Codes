#include <cstdio>
#include <iostream>
using namespace std;
int q, l, r, x;
int p[200005];
char opt[1];
int main(){
	scanf("%d", &q);
	l = 1, r = 0;
	while(q--) {
		scanf("%s%d", opt, &x);
		switch(*opt) {
		case 'L':
			p[x] = --l;
			break;
		case 'R':
			p[x] = ++r;
			break;
		case '?': printf("%d\n", min(p[x] - l, r - p[x]));
		}
	}
}
