package main

import "fmt"

func main() {
	var n int
	fmt.Scanf("%d", &n)
	for i := 1; i <= n*n; {
		for j := 1; j <= n; i, j = i+1, j+1 {
			fmt.Printf("%02d", i)
		}
		fmt.Println()
	}
	x := 1
	for i := 1; i <= n; i++ {
		fmt.Println()
		for j := 1; j <= n; j++ {
			if j <= n-i {
				fmt.Printf("  ")
			} else {
				fmt.Printf("%02d", x)
				x++
			}
		}
	}
}
