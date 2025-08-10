use std::io;
fn solution(len: u64, arr: Vec<i64>) {
    /** 1 ≤ N ≤ 100 */
    let mut ans: u64 = 0;
    for i in 0..len as usize {
        let mut les: u64 = 0;
        let mut gre: u64 = 0;
        for data in arr.iter() {
            if arr[i] >= *data {
                les += 1;
            } else {
                gre += 1;
            }
        }
        if (les - 1) >= gre {
            ans += 1;
        }
    }
    print!("{}", ans);
}
fn input() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let len: u64 = inp.trim().parse().expect("Parsing Error");
    inp.clear();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let arr: Vec<i64> = inp
        .trim()
        .split_whitespace()
        .map(|data| data.parse().expect("parsing Error"))
        .collect();
    solution(len, arr);
}
fn main() {
    let mut inp: String = String::new();
    io::stdin().read_line(&mut inp).expect("Inpput Error");
    let test: u64 = inp.trim().parse().expect("Parsing Error");
    for _ in 0..test {
        input();
        println!("");
    }
}
