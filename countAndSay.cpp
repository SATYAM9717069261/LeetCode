/**
 * class Solution {
 public: string countAndSay(int n) {
        string ans = "1";
    while (--n) {
      string next;
      for (int i = 0; i < ans.length(); ++i) {
        int count = 1;
        while (i + 1 < ans.length() && ans[i] == ans[i + 1]) {
          ++count; ++i;
        }
        next += to_string(count) + ans[i];
      }
      ans = move(next);
    }
    return ans;
  }
};
*/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: string countString(string& nums, int start, int end){
                 if(start == end)
                     return "";
                 char tmpNum = nums[start];
                 int count = 0;
                 while(tmpNum == nums[start]){
                     start++;
                     count++;
                 }
                 return to_string(count)+tmpNum+countString(nums,start,end);
             }
    public: string countAndSay(int n){
                if(n == 0)
                    return "";
                string ans = "1";
                while(--n){
                    ans = countString(ans,0,ans.length());
                }
                return ans;
            }
};

int main(){
    int num; cin>>num;
    Solution sol;
    cout<<sol.countAndSay(num);
    return 0;
}
