use std::io;
fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("Input ");
    let test = inp.trim().parse().expect("Parsing Error");
    for _ in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect("Input");
        let n: i32 = inp.trim().parse().expect("Parsing");

        inp.clear();
        io::stdin().read_line(&mut inp).expect("Input");
        let s: String = inp.trim().to_string();
        let mut count: i32 = 1;
        for i in 0..(n - 3) {
            let s_i = match s.chars().nth(i as usize) {
                Some(ch) => ch,
                _ => break,
            };
            let s_i1 = match s.chars().nth((i + 1) as usize) {
                Some(ch) => ch,
                _ => break,
            };
            let s_i2 = match s.chars().nth((i + 2) as usize) {
                Some(ch) => ch,
                _ => break,
            };
            let s_i3 = match s.chars().nth((i + 3) as usize) {
                Some(ch) => ch,
                _ => break,
            };
            println!(" {} {} {} {}", s_i, s_i1, s_i2, s_i3);
            if s_i == s_i2 && s_i1 == s_i3 && s_i != s_i1 {
                count += 1;
            }
        }
        println!("{}", count);
    }
}
