#include <cstdio>
#include <cstring>
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
struct BigInt {
	short int num[505], size;
	BigInt(){
		memset(this, 0, sizeof(BigInt));
	}
	BigInt(long long x){
		memset(this, 0, sizeof(BigInt));
		do {
			num[++size] = x % 10;
			x /= 10;
		} while(x);
	}
	BigInt operator+(BigInt x){
		BigInt t;
		int len = max(size, x.size);
		for(int i = 1; i <= len; i++) {
			t.num[i] += num[i] + x.num[i];
			t.num[i + 1] = t.num[i] / 10;
			t.num[i] %= 10;
		}
		if(t.num[len + 1] > 0) len++;
		t.size = len;
		return t;
	}
	void write(){
		for(int i = size; i > 0; i--) putchar(num[i] ^ '0');
	}
};
int ans1, f[5005], a[5005];
BigInt ans2, g[5005];
int main(){
	int n = read();
	for(int i = 1; i <= n; i++) a[i] = read();
	for(int i = 1; i <= n; i++) {
		f[i] = 1;
		for(int j = 1; j < i; j++)
			if(a[j] > a[i]) f[i] = max(f[i], f[j] + 1);
		ans1 = max(ans1, f[i]);
	}
	for(int i = 1; i <= n; i++) {
		if(f[i] == 1) g[i] = 1;
		for(int j = 1; j < i; j++) {
			if(f[i] == f[j] + 1 && a[j] > a[i]) g[i] = g[i] + g[j];
			if(f[i] == f[j] && a[j] == a[i]) g[i] = 0;
		}
		if(f[i] == ans1) ans2 = ans2 + g[i];
	}
	printf("%d ", ans1);
	ans2.write();
}
