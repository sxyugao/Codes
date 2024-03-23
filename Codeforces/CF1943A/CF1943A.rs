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
    let t: i32 = sc.next();
    for _ in 0..t {
        solve(sc, out);
    }
}

fn solve<W: Write>(sc: &mut scanner::Scanner, out: &mut std::io::BufWriter<W>) {
    let n: usize = sc.next();
    let mut cnt: Vec<i32> = vec![0; n];
    for _ in 0..n {
        let x: usize = sc.next();
        cnt[x] += 1;
    }
    let mut ans: usize = 0;
    let mut flag = false;
    writeln!(
        out,
        "{}",
        loop {
            if ans == n || cnt[ans] == 0 {
                break ans;
            }
            if cnt[ans] == 1 {
                if flag {
                    break ans;
                }
                flag = true;
            }
            ans += 1;
        }
    )
    .ok();
}
