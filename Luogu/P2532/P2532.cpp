#include <cstdio>
#include <iostream>
using namespace std;
struct BigInt {
	int len, a[10005];
	void init(){
		len = 1, a[1] = 1;
	}
	BigInt operator*(const int &b) const {
		BigInt ans;
		for(int i = 1; i <= len; i++) ans.a[i] = a[i] * b;
		for(int i = 2; i <= len; i++) {
			ans.a[i] += ans.a[i - 1] / 10;
			ans.a[i - 1] %= 10;
		}
		ans.len = len;
		while(ans.a[ans.len] > 10) {
			ans.a[ans.len + 1] = ans.a[ans.len] / 10;
			ans.a[ans.len] %= 10;
			ans.len++;
		}
		return ans;
	}
	BigInt operator/(const int &b) const {
		BigInt ans;
		int t = 0;
		for(int i = len; i; i--) {
			t = t * 10 + a[i];
			ans.a[i] = t / b; t %= b;
		}
		ans.len = len;
		while(!ans.a[ans.len]) ans.len--;
		return ans;
	}
	void print(){
		for(int i = len; i; i--) printf("%d", a[i]);
	}
} ans;
int n;
int main(){
	scanf("%d", &n);
	ans.init();
	for(int i = n + 2; i <= n * 2; i++) ans = ans * i;
	for(int i = 2; i <= n; i++) ans = ans / i;
	ans.print();
}
