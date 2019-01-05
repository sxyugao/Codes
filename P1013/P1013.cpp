#include <bits/stdc++.h>
using namespace std;
int n, num[10];
string s[10][10];
map<char, int>id;
bool check(){
	static int a[10][10];
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++) {
			if(i == 1 && j == 1) continue;
			for(int k = 0; k < (int)s[i][j].size(); k++)
				a[i][j] = a[i][j] * (n - 1) + num[id[s[i][j][k]]];
			if(i == 1 || j == 1) continue;
			if(a[i][j] != a[i][1] + a[1][j]) return 0;
		}
	return 1;
}
int main(){
	cin >> n;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= n; j++)
			cin >> s[i][j];
	for(int i = 2; i <= n; i++) id[s[1][i][0]] = i - 1;
	for(int i = 1; i < n; i++) num[i] = i - 1;
	do {
		if(check()) {
			for(int i = 2; i <= n; i++) cout << s[1][i] << '=' << num[i - 1] << ' ';
			cout << endl << n - 1 << endl;
			return 0;
		}
	} while(next_permutation(num + 1, num + n));
	cout << "ERROR!" << endl;
}
