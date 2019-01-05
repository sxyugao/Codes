#include <map>
#include <cstdio>
#include <iostream>
using namespace std;
char c;
string s, fa;
map<string, string>f;
string Find(string k){
	return f[k] == k ? k : f[k] = Find(f[k]);
}
int main(){
	cin >> c;
	while(c != '$') {
		cin >> s;
		switch(c) {
		case '#': {
			fa = s;
			if(!f[s].size()) f[s] = s;
			break;
		}
		case '+': f[s] = fa;
			break;
		case '?': cout << s << ' ' << Find(s) << endl;
			break;
		}
		cin >> c;
	}
}
