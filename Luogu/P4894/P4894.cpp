#include <cstdio>
#include <iostream>
using namespace std;
int main(){
	long long x1, y1, z1, x2, y2, z2;
	while(cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2)
		cout << y1 * z2 - z1 * y2 << ' ' << z1 * x2 - x1 * z2 << ' ' << x1 * y2 - y1 * x2 << '\n';
}
