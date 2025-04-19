#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: int sol(vector<int>& nums, int k){
                int ans = -1;
                int minPos = INT_MAX;
               for(int i:nums) {
                   if(k%i == 0 && minPos > (k/i)){
                    minPos = k/i;
                    ans = i;
                   }
               }
               
                return ans;
            }
};
int main(){
    int test; cin>>test;
    while (test--) {
      int size; cin>>size;
      vector<int> nums(size,0);
      int k; cin>>k;
      while(size--)
          cin>>nums[size];
      
      Solution sol;
      cout<<sol.sol(nums,k)<<endl;
    }
}
