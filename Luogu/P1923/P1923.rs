use std::io::Read;

fn main() {
    let mut stdin = std::io::stdin();
    let mut s = String::new();
    stdin.read_to_string(&mut s).unwrap();
    let mut sc = s.split_whitespace();
    let n: usize = sc.next().unwrap().parse().unwrap();
    let k: usize = sc.next().unwrap().parse().unwrap();
    let mut arr = Vec::<u32>::with_capacity(n);
    for _ in 0..n {
        arr.push(sc.next().unwrap().parse().unwrap());
    }
    let (_, ans, _) = arr.select_nth_unstable(k);
    println!("{}", ans);
}
