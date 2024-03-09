/** Alternate Solution My solution is Working in Local PC but its not accept in Leet Code 
 *  Problem is in line 34 divider << count +1 , Input 2147483647 2  
 *
 *  if(divident == INT_MIN && divider == -1)
 *                  return INT_MAX;
 *              if(divider == divident)
 *                  return 1;
 *              bool flag = (divident >= 0) == (divider >= 0) ? true : false;
 *              unsigned int dividnd = abs(divident);
 *              unsigned int divisor = abs(divider);
 *              unsigned int res = 0;
 *              while(dividnd >= divisor){
 *                  int count = 0;
 *                  while(dividnd > (divisor << count+1))
 *                      count++;
 *                  res += 1 << count;
 *                  dividnd -= divisor <<count;
 *              }
 *              return flag? res : -res;
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: int divid(int divident, int divider){
                 if(divident < divider)
                     return 0;
                 int count = 0;
                 while(count < 30 && divident >= (divider << (count+1)))
                     count++;
                divident -= (divider << count); 
                 return (1 << count) + divid(divident,divider );
             }

    public: int solution(int divident,int divider){
                if( divident == INT_MIN  && divider == -1)
                    return INT_MAX;
                if(divider == divident)
                    return 1;

                int mul = divider >= 0 == divident >= 0 ? 1  : -1;
                return Solution::divid(abs(divident),abs(divider)) * mul;
    
              }
};

int main(){
    int divident; cin>>divident;
    int divider; cin>>divider;
    Solution sol;
    cout<<sol.solution(divident,divider);
    return 0;
}
