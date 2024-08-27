use std::io::{self, Read};

fn main() {
    let mut stdin = io::stdin();
    let mut s = String::new();
    stdin.read_to_string(&mut s).unwrap();
    let mut iter = s.split_whitespace();
    let t: i32 = iter.next().unwrap().parse().unwrap();
    for _ in 0..t {
        let n: usize = iter.next().unwrap().parse().unwrap();
        let mut arr = Vec::<i32>::new();
        let mut flag = n == 2;
        for idx in 0..n {
            arr.push(iter.next().unwrap().parse().unwrap());
            if idx > 0 && arr[idx] - arr[idx - 1] < 2 {
                flag = false;
            }
        }
        println!("{}", if flag { "YES" } else { "NO" });
    }
}
