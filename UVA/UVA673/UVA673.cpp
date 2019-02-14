#include <cstdio>
#include <iostream>
using namespace std;
int T;
char s[150], str[150];
int main(){
	scanf("%d\n", &T);
	while(T--) {
		gets(str);
		int top = 0;
		for(int i = 0; str[i]; i++)
			if(str[i] == '(' || str[i] == '[') s[++top] = str[i];
			else{
				if(!top) {
					top++;
					break;
				}
				if(str[i] == ')' && s[top] != '(') break;
				else if(str[i] == ']' && s[top] != '[') break;
				top--;
			}
		puts(top ? "No" : "Yes");
	}
}
