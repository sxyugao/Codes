mod scanner {
    use std::str::FromStr;
    pub struct Scanner<'a> {
        it: std::str::SplitWhitespace<'a>,
    }
    impl<'a> Scanner<'a> {
        pub fn new(s: &'a String) -> Scanner<'a> {
            Scanner {
                it: s.split_whitespace(),
            }
        }
        pub fn next<T: FromStr>(&mut self) -> T {
            self.it.next().unwrap().parse::<T>().ok().unwrap()
        }
    }
}

use std::io::Write;

fn main() {
    use std::io::Read;
    let mut s = String::new();
    std::io::stdin().read_to_string(&mut s).unwrap();
    let mut sc = scanner::Scanner::new(&s);
    let out = std::io::stdout();
    let mut out = std::io::BufWriter::new(out.lock());
    run(&mut sc, &mut out);
}

fn run<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut a: Vec<i64> = Vec::new();
    for _ in 0..n {
        let x: i64 = sc.next();
        a.push(x)
    }
    for idx in 1..(n - 1) {
        if (a[idx + 1] - a[idx]) * (a[idx] - a[0]) < 0 {
            write!(out, "3\n{} {} {}", 1, idx + 1, idx + 2).ok();
            return;
        }
    }
    write!(out, "0").ok();
}
