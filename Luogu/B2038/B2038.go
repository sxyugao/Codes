package main

import "fmt"

func main() {
	var c byte
	fmt.Scanf("%c", &c)
	if c&1 == 1 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
