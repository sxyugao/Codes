#include <stdio.h>
int main() {
    int n, x, m1 = 0, m2 = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        if (x > m1) {
            m2 = m1;
            m1 = x;
        } else {
            if (x != m1 && x > m2) m2 = x;
        }
    }
    printf("%d\n", m2);
}