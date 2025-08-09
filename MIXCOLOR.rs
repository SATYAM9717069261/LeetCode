use std::cmp::max;
use std::io;

fn search(rest: &Vec<(i64, i64)>, arival: i64, len: i64) -> i64 {
    let mut start: usize = 0;
    let mut end: usize = rest.len() - 1;

    while start < end {
        let mid: usize = (start + end) / 2;
        if rest[mid].0 < arival {
            start = mid + 1;
        } else {
            end = mid;
        }
    }
    if start > 0 && rest[start - 1].0 <= arival && rest[start - 1].1 > arival {
        return 0;
    }
    if start < rest.len() {
        return rest[start].0 - arival;
    }
    return -1;
}

fn solution(len: i64, pe_time_len: i64, mut rest_time: Vec<(i64, i64)>, per_time: Vec<i64>) {
    rest_time.sort_by(|a, b| a.0.cmp(&b.0));
    for i in 0..pe_time_len as usize {
        if rest_time[(len - 1) as usize].1 <= per_time[i] {
            println!("-1");
        } else if rest_time[0].0 >= per_time[i] {
            println!("{}", (rest_time[0].0 - per_time[i]));
        } else {
            let ans: i64 = search(&rest_time, per_time[i], len);
            println!("{}", ans);
        }
    }
}

fn input() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");

    let mut iter = inp.trim().split_whitespace();
    let (len, pe_time_len): (i64, i64) = (
        iter.next()
            .unwrap()
            .parse::<i64>()
            .expect("Failed to parse input"),
        iter.next()
            .unwrap()
            .parse::<i64>()
            .expect("Failed to parse input"),
    );

    let mut rest_time: Vec<(i64, i64)> = vec![];
    for i in 0..len {
        let mut inp = String::new();
        io::stdin()
            .read_line(&mut inp)
            .expect("Failed to read line");
        let mut iter = inp.trim().split_whitespace();
        let (open, close): (i64, i64) = (
            iter.next()
                .unwrap()
                .parse::<i64>()
                .expect("Failed to parse input"),
            iter.next()
                .unwrap()
                .parse::<i64>()
                .expect("Failed to parse input"),
        );
        rest_time.push((open, close));
    }
    let mut per_time: Vec<i64> = vec![];

    for i in 0..pe_time_len {
        inp.clear();
        io::stdin()
            .read_line(&mut inp)
            .expect("Failed to read line");
        per_time.push(inp.trim().parse::<i64>().expect("Failed to parse input"));
    }
    solution(len, pe_time_len, rest_time, per_time);
}

/**
fn solution(len: i64, mut array1: Vec<i64>, mut array2: Vec<i64>) {
    let mut same: Vec<bool> = vec![false; (len + 1) as usize];
    let mut arr: Vec<bool> = vec![false; (len + 1) as usize];
    for i in 0..len as usize {
        if array1[i] == array2[i] {
            same[array1[i] as usize] = true;
        } else {
            arr[array1[i] as usize] = true;
            arr[array2[i] as usize] = true;
        }
    }
    let mut count: u8 = 0;
    let mut ans: i64 = 0;
    print!("{:?}", same);
    for i in 0..len as usize {
        if same[i] == true {
            ans += 1;
            continue;
        }
        if same[i] == false && arr[i] == false {
            print!("{} ", ans);
            return;
        }
        if arr[i] == true {
            if count == 0 {
                count = 1;
            } else {
                print!("{} ", ans);
                return;
            }
        }
        ans += 1;
    }
    print!("{} ", ans);
    return;
}
fn input() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");

    let num: i64 = inp.trim().parse().expect("Failed to parse input");

    inp.clear();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");

    let array1: Vec<i64> = inp
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i64>().expect("Failed to parse input"))
        .collect();

    inp.clear();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");

    let array2: Vec<i64> = inp
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i64>().expect("Failed to parse input"))
        .collect();

    solution(num, array1, array2);
}
**/

fn main() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");
    let test: i64 = inp.trim().parse::<i64>().expect("Failed to parse input");
    for _ in 0..test {
        input();
        println!("");
    }
}
