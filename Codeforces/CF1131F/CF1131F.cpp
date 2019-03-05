#include <cstdio>
int n, x, y, L[150005], R[150005], nxt[150005], deg[150005];
int FindL(int x) { return L[x] = x == L[x] ? x : FindL(L[x]); }
int FindR(int x) { return R[x] = x == R[x] ? x : FindR(R[x]); }
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) L[i] = R[i] = i;
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &x, &y);
    int Lx = FindL(x), Rx = FindR(x), Ly = FindL(y), Ry = FindR(y);
    R[Rx] = Ry, nxt[Rx] = Ly, L[Ly] = Lx;
    deg[Ly]++;
  }
  for (int i = 1; i <= n; i++)
    if (!deg[i])
      for (int j = i; j; j = nxt[j]) printf("%d ", j);
}