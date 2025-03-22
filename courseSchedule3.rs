/*
  [100,200] [200,1300] [1000,1250] [2000,3200]
  1. sort based in last date of completion
  2. use max heap and store it how much time course take and also maintain total time += how mush time current course take
  3. if total time  > last date of completion then  total time - top of heap (which is longest time taken course)
*/

use std::collections::BinaryHeap;
fn input() -> Vec<String> {
    let mut inp = String::new();
    std::io::stdin().read_line(&mut inp).unwrap();
    let outString: Vec<String> = inp
        .trim()
        .split(" ")
        .map(|x| x.parse().expect("iParsing Error "))
        .collect();
    return outString;
}

struct Solution;
impl Solution {
    pub fn schedule_course(mut courses: Vec<Vec<i32>>) -> i32 {
        courses.sort_by_cached_key(|v| v[1]);
        let mut bh = BinaryHeap::new();
        let mut end_: i32 = 0;

        for i in courses {
            bh.push(i[0]);
            end_ += i[0];
            if end_ > i[1] {
                if let Some(max) = bh.pop() {
                    end_ -= max;
                }
            }
        }
        return bh.len() as i32;
    }
}

fn main() {
    let inp: Vec<String> = input();
    let mut details: Vec<Vec<i32>> = vec![];
    let courses: i32 = inp[0].parse().expect("Parsing Error");
    let mut i: usize = 1;
    while i <= (courses * 2) as usize {
        let mut tmp: Vec<i32> = vec![];
        tmp.push(inp[i].parse().expect("parsing Error"));
        tmp.push(inp[i + 1].parse().expect("parsing Error"));
        details.push(tmp);
        i += 2;
    }
    let ans: i32 = Solution::schedule_course(details);
    println!("ANS +++++++++++++++> {}", ans);
}
