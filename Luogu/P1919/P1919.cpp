#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define gc c = getchar()
int read(){
	int x = 0, f = 1; char gc;
	for(; !isdigit(c); gc) if(c == '-') f = -1;
	for(; isdigit(c); gc) x = x * 10 + c - '0';
	return x * f;
}
#undef gc
const double Pi = acos(-1);
const int MAXN = 2e5 + 5;
struct Complex {
	Complex(){
		x = y = 0;
	}
	Complex(double A, double B){
		x = A, y = B;
	}
	Complex operator+(const Complex &b) const {
		Complex ans;
		ans.x = x + b.x;
		ans.y = y + b.y;
		return ans;
	}
	Complex operator-(const Complex &b) const {
		Complex ans;
		ans.x = x - b.x;
		ans.y = y - b.y;
		return ans;
	}
	Complex operator*(const Complex &b) const {
		Complex ans;
		ans.x = x * b.x - y * b.y;
		ans.y = x * b.y + y * b.x;
		return ans;
	}
	double x, y;
};
int num, rev[MAXN];
void FFT(Complex *a, int opt){
	for(int i = 0; i < num; i++)
		if(i < rev[i]) swap(a[i], a[rev[i]]);
	for(int mid = 1; mid < num; mid <<= 1) {
		Complex Wn(cos(Pi / mid), sin(Pi / mid) * opt);
		for(int len = mid << 1, j = 0; j < num; j += len) {
			Complex w(1, 0);
			for(int k = 0; k < mid; k++, w = w * Wn) {
				Complex x = a[j + k], y = w * a[j + mid + k];
				a[j + k] = x + y;
				a[j + mid + k] = x - y;
			}
		}
	}
}
Complex a[MAXN], b[MAXN];
char s[MAXN];
int ans[MAXN];
int main(){
	int n = read(), len = 0;
	scanf("%s", s);
	for(int i = n - 1; ~i; i--) a[n - i - 1].x = s[i] ^ '0';
	scanf("%s", s);
	for(int i = n - 1; ~i; i--) b[n - i - 1].x = s[i] ^ '0';
	for(num = 1; num <= 2 * n; num <<= 1) len++;
	for(int i = 0; i < num; i++)
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (len - 1));
	FFT(a, 1), FFT(b, 1);
	for(int i = 0; i <= num; i++) a[i] = a[i] * b[i];
	FFT(a, -1);
	len = num;
	for(int i = 0; i <= len; i++) {
		ans[i] += (int)round(a[i].x / num);
		if(ans[i] > 9) {
			ans[i + 1] += ans[i] / 10;
			ans[i] %= 10;
			len += (i == len);
		}
	}
	while(!ans[len] && len) len--;
	for(int i = len; ~i; i--) printf("%d", ans[i]);
}