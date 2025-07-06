use rusty_cc::{Reading, RW};

fn main() {
    let mut rw = RW::new();
    for _i in 0..rw.read() {
        let n: i64 = rw.read();
        let res = n * 5 * 3;
        writeln!(rw, "{}", res);
    }
}

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
