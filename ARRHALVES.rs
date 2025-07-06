/**
*  3
   2
   3 2 1 4
   3
   1 2 3 4 5 6
   3
   6 5 4 3 2 1
*/
use std::io;
fn solution(element: Vec<u32>, half: u32) -> u64 {
    let mut ans: u64 = 0;
    let mut count: u64 = 0;
    for i in 0..half {
        match element.get(i as usize) {
            Some(val) => {
                if ((*val as i32 - half as i32) as i32) > 0 {
                    ans += ((half - 1) - i) as u64;
                    count += 1;
                }
            }
            _ => break,
        }
    }
    for i in half..(2 * half) {
        match element.get(i as usize) {
            Some(val) => {
                if ((*val as i32 - half as i32) as i32) <= 0 {
                    ans += (i - half) as u64;
                }
            }
            _ => break,
        }
    }
    return ans + count;
}
fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("INPUT");
    let test: u32 = inp.trim().parse().expect("Parsing Error");
    for i in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect("INPUT");
        let half: u32 = inp.trim().parse().expect("Parse Error");
        inp.clear();
        io::stdin().read_line(&mut inp).expect("INPUT");
        let ele: Vec<u32> = inp
            .trim()
            .split_whitespace()
            .map(|x| x.parse().expect("parsing"))
            .collect();
        let ans: u64 = solution(ele, half);
        println!("{}", ans);
    }
}
