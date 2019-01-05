#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
string T, s[100005];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> s[i];
	sort(s + 1, s + n + 1);
	cin >> T;
	for(int i = 1; i <= n; i++)
		if(s[i].find(T) == 0) cout << s[i] << '\n';
}
