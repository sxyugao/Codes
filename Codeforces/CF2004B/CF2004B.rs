use std::cmp::{max, min};
use std::io::{self, Read};

fn main() {
    let mut stdin = io::stdin();
    let mut s = String::new();
    stdin.read_to_string(&mut s).unwrap();
    let mut scan = s.split_whitespace();
    let t: i32 = scan.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let l: i32 = scan.next().unwrap().parse().unwrap();
        let r: i32 = scan.next().unwrap().parse().unwrap();
        let l_: i32 = scan.next().unwrap().parse().unwrap();
        let r_: i32 = scan.next().unwrap().parse().unwrap();
        println!(
            "{}",
            max(
                1,
                min(r, r_) - max(l, l_) + (l != l_) as i32 + (r != r_) as i32
            )
        )
    }
}
