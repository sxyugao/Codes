use std::io;

fn main() -> io::Result<()> {
    let stdin = io::stdin();
    let mut lines = stdin.lines();
    let t: usize = lines.next().unwrap()?.parse().unwrap();
    lines
        .take(t * 3)
        .collect::<Result<Vec<_>, _>>()?
        .chunks(3)
        .for_each(|items| {
            let n: usize = items[0].parse().unwrap();
            let map = [items[1].as_bytes().to_vec(), items[2].as_bytes().to_vec()];
            let mut vis = vec![vec![false; n]; 2];
            if dfs(n, 0, 0, &map, &mut vis) {
                println!("YES")
            } else {
                println!("NO")
            }
        });
    Ok(())
}

fn dfs(n: usize, x: usize, y: usize, map: &[Vec<u8>], vis: &mut Vec<Vec<bool>>) -> bool {
    if vis[x][y] {
        return false;
    }
    vis[x][y] = true;
    if x == 1 && y == n - 1 {
        return true;
    }
    let x = x as i32;
    let y = y as i32;
    for (dx, dy) in [(0, 1), (0, -1), (1, 0), (-1, 0)] {
        let tx = x + dx;
        let mut ty = y + dy;
        if ty < 0 || ty >= n as i32 || tx < 0 || tx > 1 {
            continue;
        }
        if map[tx as usize][ty as usize] == b'<' {
            ty -= 1
        } else {
            ty += 1
        }
        if ty < 0 || ty >= n as i32 || tx < 0 || tx > 1 {
            continue;
        }
        if dfs(n, tx as usize, ty as usize, map, vis) {
            return true;
        }
    }
    false
}
