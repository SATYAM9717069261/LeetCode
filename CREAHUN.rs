use std::io;
fn ceil_div(a: i64, b: i64) -> i64 {
    if a <= 0 {
        0
    } else {
        (a + b - 1) / b
    }
}

fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect(" input Error");
    let test: i64 = inp.trim().parse().expect("parsing Error");
    for _ in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect(" input Error");
        let mut ws = inp.trim().split_whitespace();
        let n: i64 = ws.next().unwrap().parse().unwrap();
        let mut b_hel: i64 = ws.next().unwrap().parse().unwrap();

        let mut x: i64 = 0;
        let mut y: i64 = 0;
        for _ in 0..n {
            inp.clear();
            io::stdin().read_line(&mut inp).expect(" input Error");
            let mut ws = inp.trim().split_whitespace();
            let time: i64 = ws.next().unwrap().parse().unwrap();
            let dam: i64 = ws.next().unwrap().parse().unwrap();
            if time == 1 && dam > x {
                x = dam;
            }
            if time == 2 && dam > y {
                y = dam;
            }
        }
        let mut time: i64 = 0;
        while b_hel > 0 {
            if b_hel <= x {
                time += 1;
                break;
            }
            if b_hel <= y {
                time += 2;
                break;
            }

            if (2 * x) > y {
                time += (b_hel / x) as i64;
            } else {
                let strickCount: i64 = (b_hel / y) as i64;
                time += (2 * strickCount) as i64;
                b_hel -= (strickCount * y) as i64;
            }
        }
        println!("{}", time);
    }
}
