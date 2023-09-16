package main

import "fmt"

func main() {
	var c byte
	fmt.Scanf("%c", &c)
	fmt.Printf("  %c\n", c)
	fmt.Printf(" %c%c%c\n", c, c, c)
	fmt.Printf("%c%c%c%c%c\n", c, c, c, c, c)
}
