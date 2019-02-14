#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int p[50] = {
	0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43,
	47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103,
	107, 109, 113, 127, 131, 137, 139, 149, 151, 157,
	163, 167, 173, 179, 181, 191, 193, 197, 199
};
int n, f[205];
int main(){
	while(~scanf("%d", &n)) {
		memset(f, 0, sizeof(f));
		f[0] = 1;
		for(int i = 1; p[i]; i++)
			for(int j = p[i]; j <= n; j++)
				f[j] += f[j - p[i]];
		printf("%d\n", f[n]);
	}
}