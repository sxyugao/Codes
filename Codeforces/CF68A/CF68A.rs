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
    let p1: i32 = sc.next();
    let p2: i32 = sc.next();
    let p3: i32 = sc.next();
    let p4: i32 = sc.next();
    let a: i32 = sc.next();
    let b: i32 = sc.next();
    use std::cmp::{max, min};
    writeln!(
        out,
        "{}",
        max(0, min(min(min(min(p1, p2), p3), p4) - 1, b) - a + 1)
    )
    .ok();
}
