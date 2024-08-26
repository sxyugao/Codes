package main

import "fmt"

func main() {
	var x int
	fmt.Scan(&x)
	if x < 0 {
		x = -x
	}
	step := 0
	tmp := 0
	for {
		if tmp == x || (tmp > x && (tmp-x)%2 == 0) {
			fmt.Print(step)
			break
		}
		step += 1
		tmp += step
	}
}
