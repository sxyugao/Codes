#include <queue>
#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e4 + 5;
int n;
struct Data {
	int p, d;
	void input(){
		cin >> p >> d;
	}
	bool operator<(const Data &b) const {
		return d < b.d;
	}
} a[MAXN];
int work(){
	priority_queue<int>q;
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if((int)q.size() < a[i].d) {
			q.push(-a[i].p);
			ans += a[i].p;
		}else{
			if(a[i].p > -q.top()) {
				ans += q.top();
				q.pop();
				ans += a[i].p;
				q.push(-a[i].p);
			}
		}
	}
	return ans;
}
int main(){
	while(cin >> n) {
		for(int i = 1; i <= n; i++) a[i].input();
		cout << work() << '\n';
	}
}
