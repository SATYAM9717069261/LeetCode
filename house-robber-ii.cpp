#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: pair<int,int> check(vector<int>& nums, int current, int size){
                 if(current >= size)
                     return {0,0};
                 pair<int,int> next = check(nums,current+1,size);
                 return { nums[current] + next.second, max(next.first,next.second) };
             }
    public:
        int rob(vector<int>& nums) {
            pair<int,int> ans1 = check(nums,0,nums.size()-1);
            pair<int,int> ans2 = check(nums,1,nums.size());
            return max(max(ans1.first,ans1.second),max(ans2.first,ans2.second));
        }
};

int main(){
    int size; cin>>size;
    vector<int> arr;
    while (size--) {
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    int ans = sol.rob(arr);
    cout<<"ANS =>"<<ans;
    return 0;
}
