#include <cstdio>
int n, a, d;
int main(){
	char c;
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		scanf("%c", &c);
		if(c == 'A') a++;
		else d++;
	}
	if(a > d) puts("Anton");
	else if(a < d) puts("Danik");
	else puts("Friendship");
}
