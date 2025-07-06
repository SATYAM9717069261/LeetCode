use rusty_cc::{prelude::*, tup2};
use std::cmp::min;
use std::io;

fn solution(strlen: u16, str: String) -> bool {
    let mut zer: u32 = 0;
    let mut one: u32 = 0;
    for i in str.chars() {
        if i == '0' {
            zer += 1;
        } else {
            one += 1;
        }
    }
    let ans = min(zer, one);
    return (ans % 2) == 1;
}
fn main() {
    let mut inp = String::new();
    io::stdin().read_line(&mut inp).expect("INput");
    let test: u16 = inp.trim().parse().expect("Parsing Error");
    for _ in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect("INput");
        let strlen: u16 = inp.trim().parse().expect("Parsing Error");
        inp.clear();
        io::stdin().read_line(&mut inp).expect("INput");
        let str: String = inp.trim().parse().expect("PARSING");
        let ans: bool = solution(strlen, str);
        println!("{}", if ans == false { "Ramos" } else { "Zlatan" });
    }
}

//////////////////////

fn main() {
    let mut rw = RW::new();
    for _t in 0..rw.read() {
        let n: usize = rw.read();
        let txt: String = rw.read();
        let ct = txt
            .chars()
            .into_iter()
            .fold(0, |l, c| l + if c == '1' { 1 } else { 0 });
        let ct = min(ct, n - ct);
        writeln!(rw, "{}", if ct % 2 == 0 { "Ramos" } else { "Zlatan" });
    }
}
/////////////
mod rusty_cc {
    #![allow(dead_code)]
    use std::fmt::Arguments;
    use std::io::{stdin, stdout, BufWriter, Stdout, Write};
    use std::str::FromStr;

    pub mod prelude {
        pub use super::{Reading, RW};
        pub use std::cmp::{max, min};
    }

    pub trait Reading {
        fn read_line(&mut self) -> String;

        fn read<T>(&mut self) -> T
        where
            T: FromStr + Default,
        {
            self.read_line().parse().unwrap_or(T::default())
        }

        fn read_vec<T>(&mut self) -> Vec<T>
        where
            T: FromStr + Default,
        {
            let txt = self.read_line();
            let wrds = txt.split_whitespace();
            wrds.map(|wrd| wrd.parse().unwrap_or(T::default()))
                .collect()
        }
    }

    pub struct RW(BufWriter<Stdout>);

    impl RW {
        pub fn new() -> Self {
            RW(BufWriter::new(stdout()))
        }
        pub fn write_fmt<'a>(&mut self, args: Arguments<'a>) -> Result<(), ()> {
            self.0.write_fmt(args).unwrap();
            Ok(())
        }
    }

    impl Drop for RW {
        fn drop(&mut self) {
            self.0.flush().unwrap();
        }
    }

    impl Reading for RW {
        fn read_line(&mut self) -> String {
            let mut txt = String::new();
            stdin().read_line(&mut txt).unwrap();
            txt.trim().to_owned()
        }
    }

    pub fn tup2<T: Copy>(arr: Vec<T>) -> (T, T) {
        (arr[0], arr[1])
    }

    pub fn tup3<T: Copy>(arr: Vec<T>) -> (T, T, T) {
        (arr[0], arr[1], arr[2])
    }

    pub fn tup4<T: Copy>(arr: Vec<T>) -> (T, T, T, T) {
        (arr[0], arr[1], arr[2], arr[3])
    }

    pub fn hcf(a: i64, b: i64) -> i64 {
        if b == 0 {
            a
        } else {
            hcf(b, a % b)
        }
    }

    pub fn lcm(a: i64, b: i64) -> i64 {
        a * b / hcf(a, b)
    }
}
