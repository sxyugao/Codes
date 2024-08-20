package main

import "fmt"

func main() {
	var T int
	fmt.Scan(&T)
	for t := 0; t < T; t++ {
		var n, ans, x int
		fmt.Scan(&n)
		for i := 0; i < n; i++ {
			fmt.Scan(&x)
			if i%2 == 0 {
				if x > ans {
					ans = x
				}
			}
		}
		fmt.Println(ans)
	}
}
