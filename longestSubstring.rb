use std::cmp;
fn input()->Vec<String>{
  let mut inp = String::new();
  std::io::stdin().read_line(&mut inp).unwrap();
  let outString:Vec<String> = inp
    .trim()
    .split(" ")
    .map(|x| x.parse().expect("iParsing Error "))
    .collect();
  return outString;
}

fn two_d_vector(size:u32)->Vec<Vec<u32>>{
  let mut zeroVec:Vec<Vec<u32>>=vec![];
  for i in 0..=size{
      let mut tmp:Vec<u32> = vec![];
      for j in 0..=size{
          tmp.push(0);
      }
        zeroVec.push(tmp);
  }
    println!("{} {} {}",zeroVec.len(), zeroVec[0].len(), size);
    return zeroVec;
}

fn solution(inp:String)->u32{
  let strLen:u32 = inp.len() as u32 ;
  let mut matrix:Vec<Vec<u32>> = two_d_vector(strLen);
  let chars:Vec<char> = inp.chars().collect(); 
  let mut ans:u32 = 0;

  for i in 1..=strLen{
      for j in 1..=strLen{
          if chars[(i-1) as usize] == chars[(j-1) as usize] && i!=j{
              println!("{} {}",i,j);
              println!("INSIDE {} {}",chars[(i-1) as usize] , chars[(j-1) as usize]);
              matrix[i as usize][j as usize] = cmp::max(matrix[(i-1) as usize][j as usize], matrix[(i-1) as usize][(j-1) as usize]) +1;
              if ans < matrix[i as usize][j as usize]{
                  ans = matrix[i as usize][j as usize];
              }
          }
      }
  }

   for i in 0..strLen{
      for j in 0..strLen{
          print!("{}",matrix[i as usize][j as usize]); 
      }
        println!("");
   }
    
    println!("{} => {}" ,inp,ans);
    return ans;
}

fn main(){
  let inp:Vec<String> = input(); 
  assert_eq!(solution(inp[0].clone()),3);
  assert_eq!(solution(inp[1].clone()),2);
  assert_eq!(solution(inp[2].clone()),2);
}
