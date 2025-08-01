use std::io;

const MAX: u64 = 1000000007;

fn solution(num: u64) -> u64 {
    let mut ans: u64 = num;
    for i in (0..num).rev() {
        ans = ((ans * i) % MAX + (ans + i) % MAX) % MAX;
    }
    return ans;
}

fn main() {
    let mut inp: String = String::new();
    io::stdin().read_line(&mut inp).expect("");
    let test: u32 = inp.trim().parse().expect("");
    let mut pre_com: Vec<u64> = vec![0; 1000001];
    for i in 1..1000001 {
        pre_com[i as usize] =
            (pre_com[(i - 1) as usize] + i + (i * pre_com[(i - 1) as usize])) % MAX;
    }
    for i in 0..test {
        inp.clear();
        io::stdin().read_line(&mut inp).expect("");
        let num: u64 = inp.trim().parse().expect("");
        //let mut ans: u64 = solution(num);
        println!("{}", pre_com[num as usize]);
    }
}
