#include <cstdio>
#include <iostream>
using namespace std;
string s, ans;
int main(){
	cin >> s;
	for(unsigned int i = 0; i < s.size();) {
		for(; s[i] != '@' && i < s.size(); i++) ans += s[i];
		if(i < s.size()) ans += s[i];
		for(i++; s[i + 1] != '@' && i < s.size(); i++) ans += s[i];
		ans += ',';
	}
	ans.erase(ans.size() - 1, 1);
	bool f = 0;
	for(unsigned int i = 0; i < ans.size(); i++) f |= ans[i] == '@';
	if(!f) return puts("No solution"), 0;
	for(unsigned int i = 0; i < ans.size(); i++) {
		if(ans[i] == '@') {
			if(i == 0 || i == ans.size() - 1) return puts("No solution"), 0;
			if(!islower(ans[i - 1]) || !islower(ans[i + 1])) return puts("No solution"), 0;
		}
	}
	cout << ans << endl;
}
