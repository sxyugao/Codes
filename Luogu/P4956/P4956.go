package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	n /= 52
	n /= 7
	for x := 100; x > 0; x-- {
		if x >= n {
			continue
		}
		if (n-x)%3 == 0 {
			fmt.Println(x)
			fmt.Println((n - x) / 3)
			break
		}
	}
}
