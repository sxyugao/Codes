use std::cmp::max;
use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut s = String::new();
    stdin.read_to_string(&mut s).unwrap();
    let mut sc = s.split_whitespace();
    let t: i32 = sc.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = sc.next().unwrap().parse().unwrap();
        let k: i32 = sc.next().unwrap().parse().unwrap();
        let mut arr = Vec::<i32>::with_capacity(n);
        for _ in 0..n {
            arr.push(sc.next().unwrap().parse().unwrap());
        }
        arr.sort_by(|a, b| b.cmp(a));
        let mut a = 0;
        let mut b = 0;
        for i in 0_usize..(n - n % 2) {
            if i % 2 == 0 {
                a += arr[i];
            } else {
                b += arr[i];
            }
        }
        println!("{}", n as i32 % 2 * arr[n - 1] + max(a - b - k, 0));
    }
}
