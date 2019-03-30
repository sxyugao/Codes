#include <cstdio>
#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, bool> vis;
int main() {
  int A, B, C;
  scanf("%d%d%d", &A, &B, &C);
  int a = 1;
  vis[1] = 1;
  for (int i = 1; i <= 2000000; i++) {
    a = (1LL * A * a + a % B) % C;
    if (vis[a]) return printf("%d", i), 0;
    vis[a] = 1;
  }
  puts("-1");
}