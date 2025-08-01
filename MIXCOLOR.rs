use std::io;
fn solution(n: u32, mut colors: Vec<u32>) {
    colors.sort();
    let mut duplicates: u32 = 0;
    let mut prev: i32 = -1;

    for color in colors.iter() {
        if *color as i32 == prev {
            duplicates += 1;
        } else {
            prev = *color as i32;
        }
    }
    print!("ANS  ==> {}", duplicates);
}

fn input() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");
    let n: u32 = inp.trim().parse::<u32>().expect("Failed to parse input");
    inp.clear();
    let colors: Vec<u32> = inp
        .split_whitespace()
        .map(|x| x.parse::<u32>().expect("Failed to parse input"))
        .collect();
    solution(n, colors);
}

fn main() {
    let mut inp = String::new();
    io::stdin()
        .read_line(&mut inp)
        .expect("Failed to read line");
    let test: u32 = inp.trim().parse::<u32>().expect("Failed to parse input");
    for _ in 0..test {
        input();
        println!("");
    }
}
