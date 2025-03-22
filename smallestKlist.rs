/* https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/?envType=problem-list-v2&envId=mi4ms0j1
 * You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
 * We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
 * Solution
 * let suppose i have n vectors [non-decreasing order]
 * i want to compare 1st element of each vector and delete smallest element and repeat this untill
 * one of the vector is empty
 *
 * [4,10,15,24,26] [0,9,12,20] [5,18,22,30] 0, 5
 * [4,10,15,24,26] [9,12,20] [5,18,22,30] 4, 9
 * [10,15,24,26] [9,12,20] [5,18,22,30] 5, 10
 * [10,15,24,26] [9,12,20] [18,22,30] 9, 18
 * [10,15,24,26] [12,20] [18,22,30] 10, 18
 * [15,24,26] [12,20] [18,22,30] 12, 18
 * [24,26] [20] [18,22,30] 18, 24
 * [24,26] [20] [22,30] 20, 24
 * [24,26] [] [22,30]  stop
 *
*/

use std::convert::TryInto;
struct Solution;
impl Solution {
    pub fn printVec(ans: Vec<i32>) {
        for i in ans {
            print!("{} ", i);
        }
    }
    pub fn smallest_range(nums: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![0, 1000000];
        let mut index: Vec<i32> = vec![0; nums.len()]; // store current index
        let mut minElement = 0; // store which one index i have to increment
        let mut maxElement = 0;
        'outer: while true {
            let mut i = 0; // which array we access
            while i < nums.len() {
                if (nums[minElement].len() as i32) <= index[minElement] {
                    break 'outer;
                }
                if nums[i][index[i] as usize]
                    < nums[minElement as usize][index[minElement as usize] as usize]
                {
                    minElement = i;
                }

                if nums[i][index[i] as usize]
                    > nums[maxElement as usize][index[maxElement as usize] as usize]
                {
                    maxElement = i;
                }
                i += 1;
            }
            if (nums[maxElement as usize][index[maxElement as usize] as usize]
                - nums[minElement as usize][index[minElement as usize] as usize])
                < ans[1] - ans[0]
            {
                ans[0] = nums[minElement as usize][index[minElement as usize] as usize];
                ans[1] = nums[maxElement as usize][index[maxElement as usize] as usize];
            }

            index[minElement as usize] += 1;
        }
        Self::printVec(ans.clone());
        return ans;
    }
}
fn input() -> Vec<Vec<i32>> {
    /** @input
     *  array size then element 5 [4,10,15,24,26]
     */
    let mut inp = String::new();
    std::io::stdin().read_line(&mut inp).unwrap();
    let mut out: Vec<Vec<i32>> = vec![];
    let tmpVec: Vec<i32> = inp
        .trim()
        .split(" ")
        .map(|x| x.parse().expect("Parsing Error "))
        .collect();
    let mut i: usize = 0;
    let mut arraySize: usize = 0;
    while i < tmpVec.len() {
        if arraySize == 0 {
            arraySize = i + tmpVec[i] as usize;
            i += 1;
        }
        let mut tmp2: Vec<i32> = vec![];
        while i <= arraySize {
            tmp2.push(tmpVec[i]);
            i += 1;
        }
        out.push(tmp2);
        arraySize = 0;
    }
    return out;
}
fn main() {
    let inp: Vec<Vec<i32>> = input();
    let ans: Vec<i32> = Solution::smallest_range(inp);
}
