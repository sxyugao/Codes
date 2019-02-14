#include <cstdio>
#include <iostream>
using namespace std;
bool f[1 << 10] = {1};
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < (1 << n); i++) {
		for(int j = 1; j < (1 << n) - i; j++) putchar(' ');
		for(int j = i; ~j; j--) f[j] ^= f[j - 1];
		if(i & 1) {
			for(int j = 0; j <= i; j += 2)
				if(f[j]) printf("/__\\");
				else printf("    ");
		}
		else{
			for(int j = 0; j <= i; j++)
				if(f[j]) printf("/\\");
				else printf("  ");
		}
		puts("");
	}
}
