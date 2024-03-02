#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(vector<int>& nums){
                 int size = nums.size();
                 for(int i=0;i<size;i++){
                     cout<<nums[i]<<" ";
                 }
                 cout<<endl;
             }
    public: int sol(vector<int>& nums , int targ){
                sort(nums.begin(), nums.end());
                int size = nums.size();
                int small = INT_MAX;
                int res = 0;
                for (int i = 0; i < size - 1; i++) {
                    int j = i + 1;
                    int k = size - 1;
                    while (j < k) {
                        int sum = nums[i] + nums[j] + nums[k];
                        int ans = abs(sum - targ);
                        if (ans < small){
                            small = ans;
                            res = sum;
                        }
                        if (targ > sum) {
                            j++;
                            while ( j>1 && nums[j] == nums[j - 1])
                                j++;
                        } else {
                            k--;
                            while (k < size - 1 && nums[k] == nums[k + 1])
                                k--;
                        }
                    }
                }
                return res;
            } 
};

int main(){
    int size; cin>>size;
    vector<int> nums;
    while (--size) {
       int val; cin>>val; 
       nums.push_back(val);
    }
    int targ; cin>>targ;
    Solution sol;
    cout<<sol.sol(nums,targ);
    return 0;
}
