#include <cstdio>
int a[] = {220, 1184, 2620, 5020, 6232, 10744, 12285, 17296, 63020};
int b[] = {284, 1210, 2924, 5564, 6368, 10856, 14595, 18416, 76084};
int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < 9; i++) {
		if(a[i] >= n) return printf("%d %d", a[i], b[i]), 0;
		if(b[i] >= n) return printf("%d %d", b[i], a[i]), 0;
	}
}
