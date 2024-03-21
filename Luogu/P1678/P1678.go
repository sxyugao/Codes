package main

import (
	"fmt"
	"sort"
)

func main() {
	var m, n int
	fmt.Scanf("%d%d", &m, &n)
	var a, b [100000]int
	fmt.Scanf("\n")
	for i := 0; i < m; i++ {
		fmt.Scanf("%d", &a[i])
	}
	fmt.Scanf("\n")
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &b[i])
	}
	sort.Ints(a[:m])
	ans := 0
	for i := 0; i < n; i++ {
		l, r, mid := 0, m-1, 0
		tmp := 1000000000
		for l <= r {
			mid = (l + r) / 2
			if a[mid] >= b[i] {
				r = mid - 1
				if a[mid]-b[i] < tmp {
					tmp = a[mid] - b[i]
				}
			} else {
				l = mid + 1
				if b[i]-a[mid] < tmp {
					tmp = b[i] - a[mid]
				}
			}
		}
		ans += tmp
	}
	fmt.Println(ans)
}
