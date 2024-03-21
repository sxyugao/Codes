package main

import "fmt"

func isPrime(x int) bool {
	for i := 2; i*i <= x; i++ {
		if x%i == 0 {
			return false
		}
	}
	return true
}

func main() {
	var L, W, cnt int
	fmt.Scanf("%d", &L)
	x := 2
	for W+x <= L {
		for !isPrime(x) && W+x < L {
			x++
		}
		if W+x > L || !isPrime(x) {
			break
		}
		fmt.Println(x)
		cnt++
		W += x
		x++
	}
	fmt.Println(cnt)
}
