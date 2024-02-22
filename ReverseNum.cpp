#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: int solution(int num){
                bool neg = false;
                if(num < 0){
                    neg = true;
                    num *= -1;
                }
                int ans = 0; 
                while(num>0){
                    int mod = num%10;
                    ans= (ans*10) + mod;
                    num = num/10;
                }
                if(neg == true)
                    return -1*ans;
                else
                    return ans;
            }
};

int main(){
    int inp; cin>>inp;
    Solution sol;
    cout<<" ANS +> "<<sol.solution(inp);
    return 0;
}
