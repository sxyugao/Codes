#include <cstdio>
#include <iostream>
using namespace std;
char s[205];
int main(){
	scanf("%s", s);
	for(int i = 0; s[i]; i++)
		if(s[i] == '.') putchar('0');
		else{
			if(s[i + 1] == '-') putchar('2');
			else putchar('1');
			i++;
		}
}
