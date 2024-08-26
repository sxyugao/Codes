package main

import (
	"fmt"
	"os"
)

func main() {
	var s string
	fmt.Fscan(os.Stdin, &s)
	n := len(s)
	ans := 0
	top := 0
	for i := 0; i < n; i += 1 {
		if s[i] == ')' {
			if top > 0 {
				top -= 1
				ans += 2
			}
		} else {
			top += 1
		}
	}
	fmt.Print(ans)
}
