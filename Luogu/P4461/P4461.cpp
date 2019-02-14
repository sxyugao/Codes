#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;
class BigInt {
private:
static const int BASE = 100000000;
int NEG, _size;
LL num[10005];
public:
BigInt(){
	NEG = 1; _size = 1;
	memset(num, 0, sizeof(num));
}
BigInt(LL x){
	memset(this, 0, sizeof(BigInt));
	if(x < 0) x = -x, NEG = -1;
	else NEG = 1;
	_size = 0;
	do {
		num[++_size] = x % BASE;
		x = x / BASE;
	} while(x);
}
~BigInt(){
};
int size();
int operator[](int x);
bool operator==(const BigInt x);
bool operator==(const LL x);
friend bool operator==(const LL a, const BigInt b);
bool operator<(const BigInt x);
bool operator<(const LL x);
bool operator>(const BigInt x);
bool operator>(const LL x);
bool operator<=(const BigInt x);
bool operator<=(const LL x);
bool operator>=(const BigInt x);
bool operator>=(const LL x);
bool operator!=(const BigInt x);
bool operator!=(const LL x);
void operator=(const BigInt x);
void operator=(const LL x);
void operator=(const string s);
BigInt operator+(BigInt x);
BigInt operator+(LL x);
friend BigInt operator+(LL num, BigInt b);
BigInt operator-(BigInt x);
BigInt operator-(LL x);
BigInt operator*(BigInt x);
BigInt operator*(LL x);
friend BigInt operator*(LL num, BigInt b);
BigInt operator/(BigInt x);
BigInt operator/(LL x);
BigInt operator%(BigInt x);
BigInt operator%(LL x);
BigInt pow(LL x);
BigInt abs();
void read();
void write();
void writeln();
};
int BigInt::size(){
	int t = _size;
	return t;
}
int BigInt::operator[](int x){
	int t = num[x];
	return t;
}
bool BigInt::operator==(const BigInt x){
	if(NEG != x.NEG) return 0;
	if(_size != x._size) return 0;
	for(int i = 1; i <= x._size; i++)
		if(num[i] != x.num[i]) return 0;
	return 1;
}
bool BigInt::operator==(const LL x){
	BigInt t = x;
	return (*this) == t;
}
bool operator==(const LL a, BigInt b){
	return b == a;
}
bool BigInt::operator<(const BigInt x){
	if(NEG != x.NEG) {
		if(NEG == -1) return 1;
		return 0;
	}
	bool f = 0;
	if(NEG == 1) f = 1;
	if(_size < x._size) return f;
	if(_size > x._size) return !f;
	for(int i = _size; i > 0; i--) {
		if(num[i] < x.num[i]) return f;
		if(num[i] > x.num[i]) return !f;
	}
	return 0;
}
bool BigInt::operator<(const LL x){
	BigInt t = x;
	return (*this) < t;
}
bool BigInt::operator>(const BigInt x){
	return !(*this < x) && !(*this == x);
}
bool BigInt::operator<=(const BigInt x){
	return (*this < x) || (*this == x);
}
bool BigInt::operator>=(const BigInt x){
	return (*this > x) || (*this == x);
}
bool BigInt::operator!=(const BigInt x){
	return !(*this == x);
}
void BigInt::operator=(const BigInt x){
	NEG = x.NEG;
	_size = x._size;
	for(int i = 1; i <= x._size; i++) num[i] = x.num[i];
}
void BigInt::operator=(const LL x){
	(*this) = BigInt(x);
}
void BigInt::operator=(const string s){
	int len, j = 1;
	if(s[0] == '-') NEG = -1;
	if(NEG == -1) len = -1; else len = 0;
	for(int i = s.size() - 1; i >= (NEG == -1 ? 1 : 0); i--) {
		num[j] = s[i] - '0';
		j++;
	}
	_size = s.size() + len;
}
BigInt BigInt::operator+(BigInt x){
	if(this->NEG != x.NEG) {
		if(x.NEG != -1) {
			swap(NEG, x.NEG);
			swap(_size, x._size);
			swap(num, x.num);
		}
		x.NEG = 1;
		return (*this) - x;
	}
	BigInt t;
	t.NEG = this->NEG;
	int len = max(_size, x._size);
	for(int i = 1; i <= len; i++) {
		t.num[i] += num[i] + x.num[i];
		t.num[i + 1] = t.num[i] / BASE;
		t.num[i] %= BASE;
	}
	if(t.num[len + 1] > 0) len++;
	t._size = len;
	return t;
}
BigInt BigInt::operator+(LL x){
	BigInt t = x;
	return (*this) + t;
}
BigInt operator+(LL num, BigInt b){
	return b + num;
}
BigInt BigInt::operator-(BigInt x){
	BigInt t = *this, res;
	memset(res.num, 0, sizeof(res));
	res._size = max(t._size, x._size);
	bool f;
	if(t < x) {
		f = 1;
		swap(t.NEG, x.NEG);
		swap(t._size, x._size);
		swap(t.num, x.num);
	}else f = 0;
	if(x.NEG == -1) {
		x.NEG = 1;
		res = t + x;
		if(f) res.NEG = -1;
		else res.NEG = 1;
	}else{
		for(int i = 1; i <= t._size; i++) {
			res.num[i] += t.num[i] - x.num[i];
			if(res.num[i] < 0) {
				res.num[i] += BASE;
				res.num[i + 1] -= 1;
			}
		}
	}
	while(res.num[res._size] == 0 && res._size > 1) res._size--;
	if(f) res.NEG = -1;
	else res.NEG = 1;
	return res;
}
BigInt BigInt::operator-(LL x){
	BigInt t = x;
	return (*this) - t;
}
BigInt BigInt::operator*(BigInt x){
	BigInt res, t = (*this);
	res._size = t._size + x._size;
	res.NEG = t.NEG * x.NEG;
	for(int i = 1; i <= t._size; i++)
		for(int j = 1; j <= x._size; j++) {
			res.num[i + j - 1] += t.num[i] * x.num[j];
			res.num[i + j] += res.num[i + j - 1] / BASE;
			res.num[i + j - 1] = res.num[i + j - 1] % BASE;
		}
	while(res.num[res._size] == 0 && res._size > 1) res._size--;
	return res;
}
BigInt BigInt::operator*(LL x){
	BigInt t = x;
	return (*this) * t;
}
BigInt operator*(LL num, BigInt b){
	return b * num;
}
BigInt BigInt::operator/(BigInt x){
	BigInt res, t = (*this);
	if(t.abs() < x.abs()) return BigInt(0);
	res.NEG = t.NEG * x.NEG;
	res._size = t._size - x._size + 1;
	t.NEG = 1; x.NEG = 1;
	for(int i = res._size; i > 0; i--) {
		BigInt tmp;
		tmp._size = i + x._size - 1;
		tmp.NEG = 1;
		for(int j = tmp._size; j - tmp._size + x._size >= 1; j--)
			tmp.num[j] = x.num[j - tmp._size + x._size];
		while(t >= tmp) {
			res.num[i]++;
			t = t - tmp;
			if(res.num[i] > 9) {
				res.num[i] -= BASE;
				res.num[i + 1]++;
				if(i + 1 > res._size) res._size = i + 1;
			}
		}
	}
	while(res.num[res._size] == 0 && res._size > 1) res._size--;
	return res;
}
BigInt BigInt::operator/(LL x){
	BigInt res = (*this);
	if((res.NEG == -1 && x < 0) || (res.NEG == 1 && x > 0)) res.NEG = 1;
	else res.NEG = -1;
	if(x < 0) x = -x;
	LL k = 0;
	for(int i = res._size; i > 0; i--) {
		k = k * BASE + res.num[i];
		res.num[i] = k / x;
		k %= x;
	}
	while(res.num[res._size] == 0 && res._size > 1) res._size--;
	return res;
}
BigInt BigInt::operator%(BigInt x){
	BigInt t = (*this);
	if(t < x) return t;
	return t - t / x * x;
}
BigInt BigInt::operator%(LL x){
	BigInt t = (*this);
	if(t < x) return t;
	return t - t / x * x;
}
BigInt BigInt::pow(LL x){
	BigInt res = 1, val = (*this);
	while(x) {
		if(x & 1) res = res * val;
		x >>= 1;
		val = val * val;
	}
	return res;
}
BigInt BigInt::abs(){
	BigInt t = (*this);
	t.NEG = 1;
	return t;
}
void BigInt::read(){
	static char s[20000];
	scanf("%s", s);
	if(s[0] == '-') NEG = -1;
	else NEG = 1;
	_size = strlen(s);
	for(int i = NEG == -1 ? 1 : 0; i < _size; i++)
		num[_size - i] = s[i] - '0';
	if(NEG == -1) _size--;
	if(_size == 1 && num[_size] == 0) NEG = 1;
}
void BigInt::write(){
	if(NEG == -1) putchar('-');
	printf("%lld", num[_size]);
	for(int i = _size - 1; i; i--) printf("%08lld", num[i]);
}
void BigInt::writeln(){
	write();
	putchar('\n');
}
int T, n;
BigInt base = 2;
int main(){
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		if(n & 1) ((base.pow(n + 1) - 1) / 3).writeln();
		else ((base.pow(n + 1) - 2) / 3).writeln();
	}
}
