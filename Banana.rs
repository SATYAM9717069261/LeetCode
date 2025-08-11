/**https://www.codechef.com/practice/course/2to3stars/LP2TO303/problems/MINEAT */
use std::io;
fn find_position(arr: &Vec<u64>, ele: u64) -> usize {
    let mut start: usize = 0;
    let mut end: usize = arr.len();
    while end > start {
        let mid: usize = start + (end - start) / 2;
        if arr[mid] <= ele {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    return start;
}
fn solution(len: u64, arr: Vec<u64>) {
    let mut ans: Vec<u64> = Vec::new();
    for i in 0..len as usize {
        if ans.is_empty() || arr[i] > *ans.last().unwrap() {
            ans.push(arr[i]);
        } else {
            let pos: usize = find_position(&ans, arr[i]);
            if pos >= ans.len() {
                ans.push(arr[i]);
            } else {
                ans[pos] = arr[i];
            }
        }
    }
    print!("{} ", ans.len());
    for data in ans.iter() {
        print!("{} ", data);
    }
}

fn input() {
    let mut inp: String = String::new();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let len: u64 = inp.trim().parse().expect("Parsing Error");
    inp.clear();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let arr: Vec<u64> = inp
        .trim()
        .split_whitespace()
        .map(|data| data.parse().expect("Parsing error"))
        .collect();
    solution(len, arr);
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
