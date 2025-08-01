use std::cmp::{max, min};
use std::io;

const LIMIT: u64 = 1_000_000_007;

fn solution(mut len: u64, mut arr: Vec<u64>) {
    let mut target: i64 = len as i64;
    for i in 1..=10 {
        target = target - arr[(10 - i) as usize] as i64;
        if target >= 0 {
            continue;
        } else {
            print!("{}", 10 - i);
            return;
        }
    }
    print!("0");
}

fn input() {
    let mut inp: String = String::new();
    inp.clear();
    io::stdin().read_line(&mut inp).expect("");
    let arr1: Vec<u64> = inp
        .trim()
        .split_whitespace()
        .map(|data| data.parse().expect(""))
        .collect();
    print!("arr => {:?}", arr1);
    // let mut iter = inp.trim().split_whitespace();
    // let (a, b, p, q): (u64, u64, u64, u64) = (
    //     iter.next().expect("").parse().expect(""),
    //     iter.next().expect("").parse().expect(""),
    //     iter.next().expect("").parse().expect(""),
    //     iter.next().expect("").parse().expect(""),
    // );

    inp.clear();
    io::stdin().read_line(&mut inp).expect("");
    let len: u64 = inp.trim().parse().expect("");

    //inp.clear();
    //io::stdin().read_line(&mut inp).expect("");
    //let arr2: Vec<u64> = inp
    //    .trim()
    //    .split_whitespace()
    //    .map(|data| data.parse().expect(""))
    //    .collect();
    solution(len, arr1);
}
fn main() {
    let mut inp: String = String::new();
    io::stdin().read_line(&mut inp).expect("Input ");
    let test: u64 = inp.trim().parse().expect("");
    for _ in 0..test {
        input();
        println!("");
    }
}
