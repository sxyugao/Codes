#include <cstdio>
#include <iostream>
using namespace std;
char a[100], b[100];
int main(){
	gets(a); gets(b);
	int ans = 0;
	for(int i = 0; a[i]; i++) {
		if(a[i] == '0' && a[i + 1] == '0' && b[i] == '0')
			a[i] = a[i + 1] = b[i] = 'X', ans++;
		if(a[i] == '0' && b[i] == '0' && b[i + 1] == '0')
			a[i] = b[i] = b[i + 1] = 'X', ans++;
		if(a[i] == '0' && a[i + 1] == '0' && b[i + 1] == '0')
			a[i] = a[i + 1] = b[i + 1] = 'X', ans++;
		if(b[i] == '0' && a[i + 1] == '0' && b[i + 1] == '0')
			b[i] = a[i + 1] = b[i + 1] = 'X', ans++;
	}
	printf("%d", ans);
}
