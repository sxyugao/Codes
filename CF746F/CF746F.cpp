#include <set>
#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const int MAXN = 2e5 + 5;
int a[MAXN], b[MAXN];
struct Data {
	Data(){
	}
	Data(int Id, int X){
		id = Id, x = X;
	}
	int id, x;
	bool operator<(const Data &b) const {
		if(x != b.x) return x < b.x;
		return id < b.id;
	}
};
set<Data>s1, s2;
bool used[MAXN];
int main(){
	int n = read(), m = read(), k = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) b[i] = read();
	int tot = 0, sum = 0, ans = 0, j = 1;
	for(int i = 1; i <= n; i++) {
		tot += (b[i] + 1) / 2;
		sum += a[i];
		s1.insert(Data(i, b[i]));
		used[i] = 1;
		if((int)s1.size() > m) {
			auto it = s1.begin();
			tot -= (it->x + 1) / 2;
			s2.insert(*it);
			tot += it->x;
			used[it->id] = 0;
			s1.erase(it);
		}
		while(tot > k) {
			if(used[j]) {
				auto it = s1.lower_bound(Data(j, b[j]));
				tot -= (b[j] + 1) / 2;
				s1.erase(it);
				if(s2.size()) {
					it = --s2.end();
					tot -= it->x;
					used[it->id] = 1;
					s1.insert(*it);
					tot += (it->x + 1) / 2;
					s2.erase(it);
				}
			}else{
				auto it = s2.lower_bound(Data(j, b[j]));
				tot -= b[j];
				s2.erase(it);
			}
			sum -= a[j++];
		}
		ans = max(ans, sum);
	}
	printf("%d", ans);
}
