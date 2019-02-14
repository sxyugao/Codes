#include <bits/stdc++.h>
using namespace std;
int n, a[3005];
bool f[3005];
int main(){
	while(~scanf("%d", &n)) {
		memset(f, 0, sizeof(f));
		for(int i = 1; i <= n; i++) scanf("%d", a + i);
		for(int i = 2; i <= n; i++) {
			int t = a[i] - a[i - 1];
			if(t < 0) t = -t;
			if(0 < t && t < n) f[t] = 1;
		}
		bool flag = 1;
		for(int i = 1; i < n && flag; i++) flag &= f[i];
		if(flag) puts("Jolly");
		else puts("Not jolly");
	}
}
