/**https://www.codechef.com/practice/course/2to3stars/LP2TO303/problems/MINEAT */
use std::io;
fn possibleCheck(len: u64, hr: u64, arr: &Vec<u64>, val: u64) -> bool {
    let mut sum: u64 = 0;
    for data in arr.iter().copied() {
        sum += ((data + val - 1) / val);
        if sum > hr {
            return false;
        }
    }
    if sum <= hr {
        return true;
    } else {
        return false;
    }
}

fn solution(len: u64, hr: u64, arr: Vec<u64>) {
    let sum: u64 = arr
        .iter()
        .copied()
        .reduce(|acc, data| {
            return acc + data;
        })
        .unwrap_or(0);

    let mut end: u64 = sum; // ans
    let mut start: u64 = 1;
    let mut ans: u64 = sum;
    while start < end {
        let mut mid = (end + start) / 2;
        if possibleCheck(len, hr, &arr, mid) {
            ans = mid;
            end = mid;
        } else {
            start = mid + 1;
        }
    }
    print!("{}", ans);
}
fn input() {
    let mut inp: String = String::new();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let mut iter = inp.trim().split_whitespace();
    let (len, hr): (u64, u64) = (
        iter.next()
            .expect(" data not founf")
            .parse()
            .expect("Parsing Error"),
        iter.next()
            .expect(" data not founf")
            .parse()
            .expect("Parsing Error"),
    );
    inp.clear();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let mut arr: Vec<u64> = inp
        .trim()
        .split_whitespace()
        .map(|data| data.parse().expect("Parsing error"))
        .collect();
    arr.sort();
    solution(len, hr, arr);
}
fn main() {
    let mut inp: String = String::new();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let test: u64 = inp.trim().parse().expect("Parsing Error");
    for _ in 0..test {
        input();
        println!("");
    }
}
