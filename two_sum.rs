/**
 * Vec=[mem loc1, mem loc2, ..... ]
 * at the end of function input memory released
 * and pointer point to garbage memory location
 *
 * fix
 * 1. use String which create a new memory with value [
 *                  drawback it come with mutation]
 * 2. use &str with create new memory  use map
 */

fn inputdataStream() -> Vec<i32> {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input);
    let returnVec: Vec<i32> = input
        .trim()
        .split(" ")
        .map(|x| x.parse().expect("iParsing Error "))
        .collect();
    return returnVec;
}

fn inputdata() -> i32 {
    let mut input: String = String::new();
    std::io::stdin().read_line(&mut input);
    let returnVec: i32 = input.trim().parse().expect("");
    return returnVec;
}
fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
    let mut first: i32;
    let mut secand: i32;
    for (i, &num1) in nums.iter().enumerate() {
        for (j, &num2) in nums.iter().enumerate() {
            if i != j && (num1 + num2) == target {
                return vec![i as i32, j as i32];
            }
        }
    }
    return vec![];
}
fn main() {
    let vecCount: i32 = inputdata();
    let vecData: Vec<i32> = inputdataStream();
    let target: i32 = inputdata();
    for i in two_sum(vecData, target) {
        println!(" => {}", i);
    }
}
