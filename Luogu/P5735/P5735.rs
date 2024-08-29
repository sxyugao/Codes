use std::io::Read;

struct Point {
    x: f32,
    y: f32,
}

impl<'a> Point {
    fn new(sc: &mut std::str::SplitWhitespace<'a>) -> Point {
        Point {
            x: sc.next().unwrap().parse().unwrap(),
            y: sc.next().unwrap().parse().unwrap(),
        }
    }
}

fn dist(a: &Point, b: &Point) -> f32 {
    ((a.x - b.x).powi(2) + (a.y - b.y).powi(2)).sqrt()
}

fn main() {
    let mut stdin = std::io::stdin();
    let mut s = String::new();
    stdin.read_to_string(&mut s).unwrap();
    let mut sc = s.split_whitespace();
    let a = Point::new(&mut sc);
    let b = Point::new(&mut sc);
    let c = Point::new(&mut sc);
    println!("{:.2}", dist(&a, &b) + dist(&a, &c) + dist(&b, &c));
}
