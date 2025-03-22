#include<bits/stdc++.h>
using namespace std; 
class Solution {
    private:bool checkPossibleMid(int val,vector<int>& nums,int k){
                int count = 0;
                for(int i=0;i<nums.size() && count<k ;i++){
                    if(nums[i] <= val){
                        i++;
                        count++;
                    }
                }
                return count == k;
            }
    public:
        int minCapability(vector<int>& nums, int k) {
            int left = 1;
            int right = 1e9+5;
            int ans = 1e9+5;
            while(left < right){
                int mid = (right + left)/2;
                if(checkPossibleMid(mid,nums,k)){
                    ans = mid;
                    right = mid;
                }else{
                    left = mid+1;
                }
                cout<<" ANS =>"<<ans<<endl;
            }
            return ans;
        }
};
int main(){
    int nums; cin>>nums;
    vector<int> moneys;
    while(nums--){
        int tmp; cin>>tmp;
        moneys.push_back(tmp);
    }
    int maxSelection; cin>>maxSelection; 
    Solution sol;
    int ans  = sol.minCapability(moneys,maxSelection);
    cout<<" ANS =>"<<ans;
    return 0;
}
