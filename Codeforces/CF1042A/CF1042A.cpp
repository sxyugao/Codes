#include <set>
#include <cstdio>
using namespace std;
multiset<int>s;
int n, m;
int main(){
	scanf("%d%d", &n, &m);
	int Max = 0;
	for(int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		s.insert(x);
		Max = max(Max, x);
	}
	for(int i = 1; i <= m; i++) {
		int x = *s.begin(); s.erase(s.begin());
		s.insert(x + 1);
	}
	printf("%d %d", *s.rbegin(), Max + m);
}
