#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
string L, R;
int main(){
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++) {
		char c;
		scanf("%c\n", &c);
		L.push_back(c);
	}
	R = L;
	reverse(R.begin(), R.end());
	int cnt = 0;
	while(L.size()) {
		if(L < R) putchar(L[0]), L.erase(0, 1), R.erase(R.size() - 1, 1);
		else putchar(R[0]), R.erase(0, 1), L.erase(L.size() - 1, 1);
		if(++cnt % 80 == 0) putchar('\n');
	}
}
