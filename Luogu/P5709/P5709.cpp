#include <cstdio>
#include <iostream>
using namespace std;
int m, t, s;
int main() {
	cin >> m >> t >> s;
	if (t == 0) {
		cout << 0 << endl;
		return 0;
	}
	cout << max(0, m - s / t - s % t) << endl;
}