#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: vector<string> solution(string digits){
            if(digits.length() == 0)
                return {""};

            vector<string> ans;
            for(string i : solution(digits.substr(1,digits.length())) ){
                map<int,string> phone ={ {2,"abc"}, {3,"def"}, {4,"ghi"}, {5,"jkl"}, {6,"mno"}, {7,"pqrs"}, {8,"tuv"}, {9,"wxyz"},{0,""} };
                for(char j : phone[digits[0]-'0']){
                   string tmp = j+i;
                   ans.push_back(tmp);
                }
            }
            return ans;
    }
};

int main(){
    string inp; cin>>inp;
    Solution sol;
    vector<string> ans = sol.solution(inp);
    for(string i : ans)
        cout<<i<<endl;
    return 0;
}
