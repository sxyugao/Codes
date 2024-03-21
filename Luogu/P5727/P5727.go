package main

import "fmt"

func f(x int) {
	if x&1 == 0 {
		f(x / 2)
	} else if x > 1 {
		f(x*3 + 1)
	}
	fmt.Printf("%d ", x)
}

func main() {
	var n int
	fmt.Scanf("%d", &n)
	f(n)
}
