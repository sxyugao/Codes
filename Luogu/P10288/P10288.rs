use std::collections::HashMap;
use std::io::Read;

type Result<T> = std::result::Result<T, Box<dyn std::error::Error>>;

macro_rules! scan {
    ($sc:ident, $t:ty, $($var:pat),+$(,)?) => {
        $(
            let $var: $t = scan!($sc);
        )+
    };
    ($sc:ident) => {
        $sc.next().unwrap().parse()?
    }
}

fn main() -> Result<()> {
    let mut stdin = std::io::stdin();
    let mut s = String::new();
    stdin.read_to_string(&mut s)?;
    let mut sc = s.split_whitespace();
    scan!(sc, i32, t);
    for _ in 0..t {
        let mut pos = HashMap::<i32, Vec<i32>>::new();
        scan!(sc, i32, n);
        for i in 1..=n {
            pos.entry(scan!(sc))
                .and_modify(|v| v.push(i))
                .or_insert(vec![i]);
        }
        scan!(sc, i32, q);
        for _ in 0..q {
            scan!(sc, i32, l, r, x);
            let v = pos.get(&x);
            println!(
                "{}",
                v.map_or(0, |v| {
                    let r = v.binary_search(&r).unwrap_or_else(|x| x - 1) as i32;
                    let l = v.binary_search(&l).unwrap_or_else(|x| x) as i32;
                    r - l + 1
                })
            );
        }
    }

    Ok(())
}
