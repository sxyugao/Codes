#include <cstdio>
#include <iostream>
using namespace std;
int n, m, p;
int g[205][205], f[205][45];
string s, dic[10];
bool check(string s){
	for(int i = 1; i <= p; i++)
		if(s.find(dic[i]) == 0) return 1;
	return 0;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++) {
		string tmp;
		cin >> tmp;
		s += tmp;
	}
	cin >> p;
	for(int i = 1; i <= p; i++) cin >> dic[i];
	n = s.size();
	for(int i = n; i; i--)
		for(int j = i; j; j--)
			g[j][i] = g[j + 1][i] + check(s.substr(j - 1, i - j + 1));
	for(int i = 1; i <= m; i++) f[i][i] = g[i][i];
	for(int i = 1; i <= n; i++) f[i][1] = g[1][i];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < i && j <= m; j++)
			for(int k = j; k < i; k++)
				f[i][j] = max(f[i][j], f[k][j - 1] + g[k + 1][i]);
	printf("%d", f[n][m]);
}
