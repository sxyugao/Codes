package main

import (
	"bufio"
	"fmt"
	"os"
)

func pow(a, b, P int64) int64 {
	var res int64 = 1
	for b > 0 {
		if b%2 == 1 {
			res = res * a % P
		}
		a = a * a % P
		b >>= 1
	}
	return res
}

func main() {
	in := bufio.NewReader(os.Stdin)
	var P int64 = 998244353
	var n, q, x, l, r int
	fmt.Fscan(in, &n, &q)
	sum_a := make([]int, n+1)
	sum_b := make([]int, n+1)
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &x)
		sum_a[i] = sum_a[i-1] + x
	}
	for i := 1; i <= n; i++ {
		fmt.Fscan(in, &x)
		sum_b[i] = sum_b[i-1] + x
	}
	tot_a := sum_a[n]
	tot_b := sum_b[n]
	fac := make([]int64, tot_b+1)
	inv := make([]int64, tot_b+1)
	fac[0] = 1
	for i := 1; i <= tot_b; i++ {
		fac[i] = fac[i-1] * int64(i) % P
	}
	inv[tot_b] = pow(fac[tot_b], P-2, P)
	for i := tot_b - 1; i >= 0; i-- {
		inv[i] = inv[i+1] * int64(i+1) % P
	}
	sum_c := make([]int64, tot_b+1)
	sum_c[0] = 1
	for i := 1; i <= tot_b; i++ {
		sum_c[i] = sum_c[i-1] + fac[tot_b]*inv[i]%P*inv[tot_b-i]%P
		sum_c[i] %= P
	}
	div_inv := pow(pow(2, int64(tot_b), P), P-2, P)
	for i := 0; i < q; i++ {
		fmt.Fscan(in, &l, &r)
		l -= 1
		in_a, in_b := sum_a[r]-sum_a[l], sum_b[r]-sum_b[l]
		out_a, out_b := tot_a-in_a, tot_b-in_b
		x := out_a + out_b - in_a
		if x >= tot_b {
			fmt.Print("0 ")
		} else if x < 0 {
			fmt.Print("1 ")
		} else {
			fmt.Printf("%d ", sum_c[tot_b-x-1]*div_inv%P)
		}
	}
}
