#include<bits/stdc++.h>
using namespace std;
class Solution {
    int mem[101];
    private: int solve(string& s, int index,int& len){
                 if(mem[index] != -1)
                     return mem[index];

                 if(len == index)
                     return 1;
                 if(s[index] == '0')
                     return 0;

                 int count = solve(s,index+1,len);
                 if((index+1)<len && (s[index] == '1' || (s[index] == '2' && s[index+1] < '7'))){
                     count += solve(s,index+2,len);
                 }
                 mem[index] = count;
                return count;
             }
    public: int numDecodings(string s) {
                memset(mem,-1,sizeof(mem));
                int len  = s.length();
                return solve(s,0,len);
            }
};
int main(){
    string inp; cin>>inp;
    Solution sol;
    int count = sol.numDecodings(inp);
    cout<<"COUNT+>"<<count;
    return 0;
}
