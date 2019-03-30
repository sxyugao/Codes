#include <cstdio>
#include <iostream>
using namespace std;
string str, s;
int main(){
	cin >> str;
	s += str[0];
	for(int i = 1; i < (int)str.size(); i++)
		if(str[i] != s[s.size() - 1]) s += str[i];
	int ans = s[0] == '0';
	s[0] = '1';
	for(int i = 1; i < (int)s.size(); i++)
		if(s[i] == '0') {
			ans++;
			if(s[i - 1] == '1') ans++;
			s[i] = '1';
		}
	printf("%d", ans);
}
