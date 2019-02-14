#include <cstdio>
#include <iostream>
using namespace std;
int R, B, C, D, E;
int main(){
	scanf("%d%d%d%d%d", &R, &B, &C, &D, &E);
	int ans = R * C + B * D;
	if(2 * E > C + D) ans += min(R, B) * (2 * E - C - D);
	printf("%d", ans);
}
