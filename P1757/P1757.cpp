#include <cstdio>
#include <vector>
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
struct Data {
	Data(){
	}
	Data(int W, int V){
		w = W; v = V;
	}
	int w, v;
};
vector<Data>v[105];
int f[1005];
int main(){
	int m = read(), n = read();
	for(int i = 1; i <= n; i++) {
		int a = read(), b = read(), c = read();
		v[c].push_back(Data(a, b));
	}
	for(int i = 1; i <= 100; i++)
		for(int j = m; j >= 0; j--)
			for(Data x : v[i])
				if(j >= x.w) f[j] = max(f[j], f[j - x.w] + x.v);
	printf("%d", f[m]);
}
