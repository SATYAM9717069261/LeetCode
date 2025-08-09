use std::cmp::max;
use std::io;
fn solution(mut arr: Vec<i64>) {
    let mut track: Vec<u64> = vec![];
    let mut check: bool = true;
    let mut idx: u64 = 1;
    while true {
        if idx == arr.len() as u64 {
            idx = 1;
            if check == true {
                break;
            } else {
                check = true;
                continue;
            }
        }
        if arr[(idx - 1) as usize] > arr[idx as usize] {
            track.push(idx - 1);
            arr[(idx - 1) as usize] ^= arr[idx as usize];
            arr[idx as usize] ^= arr[(idx - 1) as usize];
            arr[(idx - 1) as usize] ^= arr[idx as usize];
            check = false;
        }
        idx += 1;
    }
    println!("{}", track.len());
    for i in 0..track.len() {
        print!("{} ", track[i]);
    }
}

fn input() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");

    // let mut iter = inp.trim().split_whitespace();
    // let (len, pe_time_len): (i64, i64) = (
    //     iter.next()
    //         .unwrap()
    //         .parse::<i64>()
    //         .expect("Failed to parse input"),
    //     iter.next()
    //         .unwrap()
    //         .parse::<i64>()
    //         .expect("Failed to parse input"),
    // );

    // let mut rest_time: Vec<(i64, i64)> = vec![];
    // for i in 0..len {
    //     let mut inp = String::new();
    //     io::stdin()
    //         .read_line(&mut inp)
    //         .expect("Failed to read line");
    //     let mut iter = inp.trim().split_whitespace();
    //     let (open, close): (i64, i64) = (
    //         iter.next()
    //             .unwrap()
    //             .parse::<i64>()
    //             .expect("Failed to parse input"),
    //         iter.next()
    //             .unwrap()
    //             .parse::<i64>()
    //             .expect("Failed to parse input"),
    //     );
    //     rest_time.push((open, close));
    // }
    //let mut per_time: Vec<i64> = vec![];

    //for i in 0..pe_time_len {
    //    inp.clear();
    //    io::stdin()
    //        .read_line(&mut inp)
    //        .expect("Failed to read line");
    //    per_time.push(inp.trim().parse::<i64>().expect("Failed to parse input"));
    //}
    let mut arr: Vec<i64> = inp
        .trim()
        .split_whitespace()
        .map(|x| x.parse::<i64>().expect("Failed to parse input"))
        .collect::<Vec<i64>>();
    solution(arr);
}

fn main() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");
    let test: i64 = inp.trim().parse::<i64>().expect("Failed to parse input");
    //for _ in 0..test {
    input();
    //        println!("");
    // }
}
