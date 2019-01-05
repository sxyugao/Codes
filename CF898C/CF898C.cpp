#include <bits/stdc++.h>
using namespace std;
map<string, int>id;
vector<string>v, a[25];
bool del[405];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int n, cnt = 0;
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		if(!id[s]) {
			id[s] = ++cnt;
			v.push_back(s);
		}
		int num;
		int cur = id[s];
		cin >> num;
		while(num--) {
			cin >> s;
			a[cur].push_back(s);
		}
	}
	cout << v.size() << endl;
	for(string s : v) {
		memset(del, 0, sizeof(del));
		int num = id[s], cnt = 0;
		for(int i = 0; i < (int)a[num].size(); i++)
			for(int j = 0; j < (int)a[num].size(); j++)
				if(i ^ j && !del[i] && !del[j] && a[num][i].size() >= a[num][j].size()) {
					string str = a[num][i].substr(a[num][i].size() - a[num][j].size(), a[num][j].size());
					if(str == a[num][j]) {
						del[j] = 1;
						cnt++;
					}
				}
		cout << s << ' ' << a[num].size() - cnt;
		for(int i = 0; i < (int)a[num].size(); i++)
			if(!del[i]) cout << ' ' << a[num][i];
		cout << endl;
	}
}
