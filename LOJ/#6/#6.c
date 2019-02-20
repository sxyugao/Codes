#include <stdio.h>
int n, a[100];
int guess(int p) {
  int l = 0, r = 1e6, x;
  while (l < r) {
    int mid = (l + r) >> 1;
    printf("guess %d %d\n", p, mid);
    fflush(stdout);
    scanf("%d", &x);
    if (x == -1) l = mid + 1;
    if (x == 0) return mid;
    if (x == 1) r = mid - 1;
  }
  return l;
}
int main() {
  puts("get_num");
  fflush(stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++) a[i] = guess(i);
  printf("submit");
  for (int i = 0; i < n; i++) printf(" %d", a[i]);
  puts("");
  fflush(stdout);
}