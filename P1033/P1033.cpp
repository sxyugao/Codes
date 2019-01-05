#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
const double eps = 1e-4;
double H, S1, V, L, K, n;
int main(){
	scanf("%lf%lf%lf%lf%lf%lf", &H, &S1, &V, &L, &K, &n);
	double Mx = S1 - V * sqrt((H - K) / 5) + L + eps, Mn = S1 - V * sqrt(H / 5) - eps;
	printf("%d", max((int)min(floor(Mx), n - 1) - max((int)ceil(Mn), 0) + 1, 0));
}
