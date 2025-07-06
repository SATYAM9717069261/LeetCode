use std::io;
fn findstartOnes(mut num: u64) -> u8 {
    let mut pos: u8 = 0;
    for i in 0..64 {
        if ((num >> i) ^ 0) == 1 {
            break;
        }
        pos += 1;
    }
    return pos;
}

fn pow(mut n: u8, mut p: u8) -> u64 {
    let mut base = n as u64;
    let mut ans: u64 = 1;

    while p != 0 {
        if p % 2 == 1 {
            ans *= base;
        }
        base *= base;
        p /= 2;
    }
    ans
}

fn twoPow(mut n: u8) -> u64 {
    let mut ans: u64 = 1;
    let mut i = 1;
    while n >= i {
        ans = (ans << 1) ^ 1;
        i += 1;
    }
    return ans;
}

fn solution(a: u64, b: u64, n: u64) -> i8 {
    if a == b {
        return 0;
    }
    let x: u64 = a ^ b;
    println!(
        "x= > {} {} {} {}",
        x,
        n,
        findstartOnes(n),
        twoPow(findstartOnes(n))
    );
    if x > 0 && x <= (n - 1) {
        return 1;
    } else if n > 1 && twoPow(findstartOnes(x)) == twoPow(findstartOnes(n)) {
        return 2;
    } else {
        return -1;
    }
}

fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("Input Error");
    let test_cases: u64 = inp.trim().parse().expect("PARSING ERROR");

    for _ in 0..test_cases {
        // inp.clear();
        // io::stdin().read_line(&mut inp).expect("Input Error");
        // let len: u64 = inp.trim().parse().expect("");

        // inp.clear();
        // io::stdin().read_line(&mut inp).expect("Input Error");
        // let mut iter = inp.trim().split_whitespace();
        // let arr1: Vec<u64> = iter.map(|data| data.parse().expect("")).collect();

        inp.clear();
        io::stdin().read_line(&mut inp).expect("Input Error");
        let mut iter = inp.trim().split_whitespace();
        let (a, b, n): (u64, u64, u64) = (
            iter.next().expect("").parse().expect(""),
            iter.next().expect("").parse().expect(""),
            iter.next().expect("").parse().expect(""),
        );

        let ans: i8 = solution(a, b, n);
        println!("{}", ans);
    }
}
