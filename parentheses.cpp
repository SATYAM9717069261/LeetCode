#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void pattern(int open, int close, string& str, vector<string>& ans){
                if(open == 0 && close == 0){
                    ans.push_back(str);
                    return ;
                }
                if(open > 0){
                    str.push_back('(');
                    pattern(open-1,close,str,ans);
                    str.pop_back();
                }
                if(open < close && close>0){
                    str.push_back(')');
                    pattern(open,close-1,str,ans);
                    str.pop_back();
                }
             }
    public: vector<string> generateParenthesis(int n) {
                vector<string> ans;
                string tmp = "";
                Solution::pattern(n,n,tmp,ans); 
                return ans;
    }
};

int main(){
    int num; cin>>num;
    Solution sol;
    for(string i: sol.generateParenthesis(num))
        cout<<i<<endl;
    return 0;
}
