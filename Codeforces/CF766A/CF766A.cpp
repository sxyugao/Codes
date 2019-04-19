#include <cstdio>
#include <iostream>
using namespace std;
string a, b;
int main() {
    cin >> a >> b;
    if (a == b) return puts("-1"), 0;
    cout << max(a.size(), b.size()) << endl;
}