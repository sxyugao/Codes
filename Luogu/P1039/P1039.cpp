#include <bits/stdc++.h>
using namespace std;
string Day[] = {"Monday.", "Tuesday.", "Wednesday.", "Thursday.", "Friday.", "Saturday.", "Sunday."};
string s1 = "I am guilty.";
string s2 = "I am not guilty.";
string s3 = " is guilty.";
string s4 = " is not guilty.";
string s5 = "Today is ";
int n, m, p, cnt, f[25];
string s, str, ans, name[25];
vector<string>sentence[25];
bool fff = 1, vis[25];
void dfs(int k, int used){
	if(used > n) return;
	if(k > m) {
		if(used != n) return;
		string p;
		int num = 0, today = -1;
		memset(f, -1, sizeof(f));
		bool flag = 1;
		for(int i = 1; i <= m; i++) {
			if(vis[i]) continue;
			for(string s : sentence[i]) {
				if(s == s1) {
					if(f[i] == 0) flag = 0;
					f[i] = 1;
				}
				if(s == s2) {
					if(f[i] == 1) flag = 0;
					f[i] = 0;
				}
				for(int j = 1; j <= m; j++)
					if(name[j] + s3 == s) {
						if(f[j] == 0) flag = 0;
						f[j] = 1;
					}else{
						if(name[j] + s4 == s) {
							if(f[j] == 1) flag = 0;
							f[j] = 0;
						}
					}
				for(int j = 0; j < 7; j++)
					if(s5 + Day[j] == s) {
						if(~today && today != j) flag = 0;
						today = j;
					}
			}
		}
		for(int i = 1; i <= m; i++) {
			if(!vis[i]) continue;
			for(string s : sentence[i]) {
				if(s == s1) {
					if(f[i] == 1) flag = 0;
					f[i] = 0;
				}
				if(s == s2) {
					if(f[i] == 0) flag = 0;
					f[i] = 1;
				}
				for(int j = 1; j <= m; j++)
					if(name[j] + s3 == s) {
						if(f[j] == 1) flag = 0;
						f[j] = 0;
					}else{
						if(name[j] + s4 == s) {
							if(f[j] == 0) flag = 0;
							f[j] = 1;
						}
					}
				for(int j = 0; j < 7; j++)
					if(s5 + Day[j] == s)
						if(today == j) flag = 0;
			}
		}
		for(int i = 1; i <= m; i++)
			if(f[i] == 1) {
				num++;
				p = name[i];
			}
		if(!num) {
			for(int i = 1; i <= m; i++)
				if(f[i] == -1) {
					num++;
					p = name[i];
				}
		}
		if(!num) flag = 0;
		for(int i = 1; i <= m; i++) fff &= f[i] == -1;
		if(num > 1) flag = 0;
		if(flag) {
			if(ans != p) cnt++;
			ans = p;
		}
		return;
	}
	vis[k] = 1;
	dfs(k + 1, used + 1);
	vis[k] = 0;
	dfs(k + 1, used);
}
int main(){
	cin >> m >> n >> p;
	for(int i = 1; i <= m; i++) cin >> name[i];
	for(int i = 1; i <= p; i++) {
		cin >> s;
		s.erase(s.size() - 1, 1);
		getline(cin, str);
		while(isspace(str[str.size() - 1])) str.erase(str.size() - 1, 1);
		str.erase(0, 1);
		for(int j = 1; j <= m; j++)
			if(name[j] == s) {
				sentence[j].push_back(str);
				break;
			}
	}
	dfs(1, 0);
	if(!cnt) {
		if(fff) puts("Cannot Determine");
		else puts("Impossible");
	}
	else{
		if(cnt > 1) puts("Cannot Determine");
		else cout << ans << endl;
	}
}
