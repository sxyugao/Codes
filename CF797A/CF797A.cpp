#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;
int n, k;
vector<int>ans;
int main(){
	scanf("%d%d", &n, &k);
	int num = k; k--;
	for(int i = 2; i <= n && k; i++)
		while(n % i == 0 && k) {
			ans.push_back(i);
			n /= i;
			k--;
		}
	if(n > 1) ans.push_back(n);
	if((int)ans.size() != num) return puts("-1"), 0;
	for(int x : ans) printf("%d ", x);
}
