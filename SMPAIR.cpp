#include<bits/stdc++.h>
using namespace std;
class Solution {
    public: int sol(vector<int>& nums,int k){
                int leftSum = 0;
                int rightSum = 0;
                sort(nums.begin(),nums.end());
                int i=0;
                if(k <= (nums.size()/2)){
                   for(i;i<k;i++)
                       leftSum+=nums[i];
                   for(i;i<nums.size();i++)
                       rightSum+=nums[i];
                }else{
                    for(i;i< nums.size() - k;i++)
                       leftSum+=nums[i];
                   for(i;i<nums.size();i++)
                       rightSum+=nums[i];
                }
                return abs(rightSum - leftSum);
            }
};
int main(){
    int test; cin>>test;
    while (test--) {
      int size; cin>>size;
      vector<int> nums(size,0);
      int k; cin>>k;

      while(size--){
          cin>>nums[size];
      }
      Solution sol;
      cout<<sol.sol(nums,k);
    }
}
