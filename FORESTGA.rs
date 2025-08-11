use std::io;
fn check(len: u64, req: u64, rest: u64, arr: &Vec<(u64, u64)>, guess: u64) -> bool {
    let mut sum: u64 = 0;
    for i in 0..len as usize {
        let _sum_tree = arr[i].0 + (guess * arr[i].1);
        if _sum_tree >= rest {
            sum += _sum_tree;
        }
        if sum >= req {
            return true;
        }
    }
    return sum >= req;
}
fn solution(len: u64, req: u64, rest: u64, arr: Vec<(u64, u64)>) {
    let mut start: u64 = 0; // if all tree are Grown
    let mut end: u64 = 2_000_000_000_000_000_000;
    let mut ans: u64 = end;
    while end >= start {
        let mid: u64 = start + (end - start) / 2;
        if check(len, req, rest, &arr, mid) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    print!("{}", ans);
}
fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("");
    let mut iter = inp.trim().split_whitespace();
    let (len, req, rest): (u64, u64, u64) = (
        iter.next().expect("Data").parse().expect("Parsing Error"),
        iter.next().expect("Data").parse().expect("Parsing Error"),
        iter.next().expect("Data").parse().expect("Parsing Error"),
    );
    let mut arr: Vec<(u64, u64)> = Vec::new();
    for _ in 0..len {
        inp.clear();
        io::stdin().read_line(&mut inp).expect("Input");
        let mut iter = inp.trim().split_whitespace();
        arr.push((
            iter.next().expect("Data").parse().expect(""),
            iter.next().expect("Data").parse().expect(""),
        ));
    }
    solution(len, req, rest, arr);
}
