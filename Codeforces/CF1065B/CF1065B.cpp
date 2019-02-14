#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
long long n, m;
int main(){
	scanf("%lld%lld", &n, &m);
	printf("%lld %lld", max(0LL, n - m * 2), n - (m ? (int)ceil((1 + sqrt(1 + 8 * m)) / 2) : 0));
}
