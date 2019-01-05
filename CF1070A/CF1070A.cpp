#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
int d, s;
bool vis[500][5005];
struct Data {
	int sum, mod;
	Data push(int x){
		Data New;
		New = *this;
		New.sum += x;
		New.mod = (New.mod * 10 + x) % d;
		return New;
	}
	bool correct(){
		if(vis[mod][sum]) return 0;
		if(sum > s) return 0;
		return 1;
	}
};
Data pre[500][5005];
int num[500][5005];
void print(Data x){
	if(!x.sum) return;
	print(pre[x.mod][x.sum]);
	printf("%d", num[x.mod][x.sum]);
}
int main(){
	scanf("%d%d", &d, &s);
	queue<Data>q;
	Data now;
	for(int i = 1; i <= 9; i++) {
		q.push(now.push(i));
		vis[i % d][i] = 1;
		num[i % d][i] = i;
	}
	while(!q.empty()) {
		now = q.front(); q.pop();
		if(!now.mod && now.sum == s) return print(now), 0;
		for(int i = 0; i <= 9; i++) {
			Data nxt = now.push(i);
			if(!nxt.correct()) continue;
			q.push(nxt);
			num[nxt.mod][nxt.sum] = i;
			pre[nxt.mod][nxt.sum] = now;
			vis[nxt.mod][nxt.sum] = 1;
		}
	}
	puts("-1");
}
