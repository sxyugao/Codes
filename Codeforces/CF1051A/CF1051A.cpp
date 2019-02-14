#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int main(){
	int T;
	static char s[100];
	scanf("%d", &T);
	while(T--) {
		scanf("%s", s);
		int len = strlen(s);
		int lower = 0, upper = 0, digit = 0;
		for(int i = 0; i < len; i++) {
			if(islower(s[i])) lower++;
			if(isupper(s[i])) upper++;
			if(isdigit(s[i])) digit++;
		}
		int cnt = bool(lower) + bool(upper) + bool(digit);
		if(cnt == 2) {
			if(lower > 1) {
				for(int i = 0; i < len; i++) {
					if(islower(s[i])) {
						if(!upper) s[i] = 'A';
						else s[i] = '1';
						break;
					}
				}
			}else{
				if(upper > 1) {
					for(int i = 0; i < len; i++) {
						if(isupper(s[i])) {
							if(!lower) s[i] = 'a';
							else s[i] = '1';
							break;
						}
					}
				}else{
					if(digit > 1) {
						for(int i = 0; i < len; i++)
							if(isdigit(s[i])) {
								if(!lower) s[i] = 'a';
								else s[i] = 'A';
								break;
							}
					}
				}
			}
		}
		if(cnt == 1) {
			if(lower) {
				for(int i = 0; i < len - 1; i++) {
					if(islower(s[i]) && islower(s[i + 1])) {
						s[i] = 'A'; s[i + 1] = '1';
						break;
					}
				}
			}
			if(upper) {
				for(int i = 0; i < len - 1; i++) {
					if(isupper(s[i]) && isupper(s[i + 1])) {
						s[i] = 'a'; s[i + 1] = '1';
						break;
					}
				}
			}
			if(digit) {
				for(int i = 0; i < len - 1; i++) {
					if(isdigit(s[i]) && isdigit(s[i + 1])) {
						s[i] = 'A'; s[i + 1] = 'a';
						break;
					}
				}
			}
		}
		if(!cnt) {
			s[0] = 'a';
			s[1] = 'A';
			s[2] = '1';
		}
		puts(s);
	}
}
