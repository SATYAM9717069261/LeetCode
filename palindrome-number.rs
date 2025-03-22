struct Solution;
impl Solution {
    pub fn input() -> i32 {
        let mut inp: String = String::new();
        std::io::stdin().read_line(&mut inp);
        let output: i32 = inp.trim().parse().expect("Parsing Fail");
        return output;
    }
    pub fn is_palindrome(x: i32) -> bool {
        let mut inp: i32 = x;
        let mut rev: i32 = 0;
        let mut mulfactor: i32 = 10;
        while inp > 9 {
            rev = (rev * mulfactor) + (inp % 10);
            inp = inp / 10;
        }
        rev = (rev * mulfactor) + (inp % 10);
        return rev == x;
    }
}

fn main() {
    let inp: i32 = Solution::input();
    println!("INPUT {}", inp);
    let result = Solution::is_palindrome(inp);
    print!("OUTPUT => {}", result);
}
