/**
 * Vector, copy data from one vector to another
 * Sort, cmpare, Swap
 */
use std::io;
use std::{cmp, mem};

fn solution(data: Vec<u32>, n: u32, mut k: u32) -> bool {
    let mut start = 0;
    let end: u32 = n;
    let mut mot: Vec<u32> = Vec::new();
    let mut tom: Vec<u32> = Vec::new();

    while start < end {
        match data.get(start as usize) {
            Some(val) => mot.push(*val),
            _ => break,
        }
        match data.get((start + 1) as usize) {
            Some(val) => tom.push(*val),
            _ => break,
        }

        start += 2;
    }

    mot.sort_by(|b, a| a.cmp(b)); // 4,3,2,1
    tom.sort(); // 1,2,3,4
    for i in 0..=cmp::min(mot.len(), tom.len()) {
        if k > 0 as u32 && mot[i as usize] > tom[i as usize] {
            mem::swap(&mut mot[i as usize], &mut tom[i as usize]);
            k -= 1;
        } else {
            break;
        }
    }
    let tom_sum: u32 = tom.iter().sum();
    let mot_sum: u32 = mot.iter().sum();
    if tom_sum > mot_sum {
        return true;
    } else {
        return false;
    }
}
fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("input");
    let test: u32 = inp.trim().parse().expect("");
    for _ in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect("input");
        let mut iter = inp.trim().split_whitespace();
        let n: u32 = iter.next().expect("").parse().expect("");
        let k: u32 = iter.next().expect("").parse().expect("");

        inp.clear();
        io::stdin().read_line(&mut inp).expect("input");

        let arr: Vec<u32> = inp
            .trim()
            .split_whitespace()
            .map(|data| data.parse().expect(""))
            .collect();
        let ans: bool = solution(arr, n, k);
        println!("{}", if ans == true { "YES" } else { "NO" });
    }
}
