use std::cmp::max;
/**
  2
  2
  10 -10
  7
  -3 -2 -1 0 1 2 3 => -3 1 -1 0 -2 2 3

    2 + -1 + 1 + 3 = 0
    -2 + 0 + -3 = 0

    -3 + -1 + -2 + 3 = -3
    1+0+2 = 3

*/
use std::io;

fn solution(size: u32, arr: Vec<i32>) -> i64 {
    let mut maxEvenElem: i64 = i64::MIN;
    let mut minOddElem: i64 = i64::MAX;
    let mut sum: i64 = 0;

    for i in 0..size {
        match arr.get(i as usize) {
            Some(data) => {
                if (i + 1) % 2 == 0 {
                    sum -= *data as i64;
                    if maxEvenElem < *data as i64 {
                        maxEvenElem = *data as i64;
                    }
                } else {
                    sum += *data as i64;
                    if minOddElem > *data as i64 {
                        minOddElem = *data as i64;
                    }
                }
            }
            _ => break,
        }
    }

    return max(sum, sum + 2 * (maxEvenElem - minOddElem));
}
fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect(" INPUT");
    let test: u64 = inp.trim().parse().expect("");
    for _ in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect(" INPUT");
        let size: u32 = inp.trim().parse().expect("size Parsing Error");
        inp.clear();
        io::stdin().read_line(&mut inp).expect(" INPUT");
        let arr: Vec<i32> = inp
            .trim()
            .split_whitespace()
            .map(|x| x.parse::<i32>().expect("").abs())
            .collect();

        let ans: i64 = solution(size, arr);
        println!("{}", ans);
    }
}
