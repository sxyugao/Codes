#include <cstdio>
#include <iostream>
using namespace std;
string s1, s2;
int main(){
	long long ans = 1;
	cin >> s1 >> s2;
	for(int i = 0; i < (int)s1.size() - 1; i++)
		for(int j = 1; j < (int)s2.size(); j++)
			if(s1[i] == s2[j] && s1[i + 1] == s2[j - 1]) ans *= 2;
	printf("%lld", ans);
}
