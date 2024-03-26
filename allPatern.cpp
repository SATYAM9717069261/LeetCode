/**
class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums)
        {
            static const int fs[] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
            int r = 1;
            int cs[21] = {0};
            for (int n : nums) {
                r *= ++cs[n + 10];
            }
            vector<vector<int>> ps(fs[nums.size()] / r);
            for (auto& p : ps) {
                p = nums;
                next_permutation(begin(nums), end(nums));
            }
            return ps;
        }
};
**/
#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void swap(int& a, int& b){
                 int tmp = a;
                 a = b;
                 b=tmp;
             }
             void permutaion(vector<int> nums, int start, int end, set<vector<int>>& ans){
                 if(start == end){
                     ans.insert(nums);
                     return ;
                 }

                 for(int i = start;i<=end;i++){
                     swap(nums[i],nums[start]);
                     permutaion(nums,start+1,end,ans);
                 }
                 return;
             }
    public: vector<vector<int>> sol(vector<int>& nums){
                vector<vector<int>> finalAns;
                set<vector<int>> ans;
                permutaion(nums,0,nums.size()-1,ans);
                for(vector<int> i: ans)
                    finalAns.push_back(i);
                return finalAns;
            }
            void print(vector<vector<int>> nums){
                for(vector<int> i: nums){
                    for(int j: i){
                        cout<<j<<" ";
                    }
                    cout<<endl;
                }
            }
};

int main(){
    int len; cin>>len;
    vector<int> nums;
    while(len--){
        int tmp;cin>>tmp;
        nums.push_back(tmp);
    }
    Solution Sol;
    Sol.print(Sol.sol(nums));
    return 0;
}
