#include <cstdio>
#include <vector>
using namespace std;
int a[105], p[105], q[100005] = {1};
int main(){
	int n, k;
	scanf("%d%d", &n, &k);
	for(int i = 1; i <= n; i++) scanf("%d", a + i);
	int num = 0;
	while(num < k) {
		int Min = 0x7fffffff;
		for(int i = 1; i <= n; i++)
			Min = min(Min, q[p[i]] * a[i]);
		q[++num] = Min;
		for(int i = 1; i <= n; i++)
			if(q[p[i]] * a[i] == Min) p[i]++;
	}
	printf("%d", q[num]);
}
