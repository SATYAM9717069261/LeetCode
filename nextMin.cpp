/**
 *  LexicoGraphical Order
 *  1. Find Largest i such That K[i-1] < k{i]
 *  2. Find largest j sucj that k[i-1] < k[j]
 *  3. Swap k[i-1] with k[j]
 *  4. Reverse k[i] - to - k[n]
 */


#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void swap(int& a, int& b){
                 int tmp = a;
                 a = b;
                 b = tmp;
             }
             void print(vector<int>& nums){
                 for(int i: nums)
                     cout<<i<<" ";
             }

    public: void permutation(vector<int>& nums){
                int ind = -1;
                int n=(int)nums.size()-1;
                for(int  i =n-1;i>=0;i--){
                    if(nums[i] < nums[i+1]){
                        ind = i;
                        break;
                    }
                }
                if(ind == -1){
                    reverse(nums.begin(),nums.end());
                }else{
                    for(int i=n;i>ind;i--){
                        if(nums[i] > nums[ind]){
                            swap(nums[i],nums[ind]);
                            break;
                        }
                    }
                    reverse(nums.begin()+ind+1,nums.end());
                }
                print(nums);
            }
};
int main(){
    int size; cin>>size;
    vector<int> data;
    while(size--){
        int tmp; cin>>tmp;
        data.push_back(tmp);
    }
    Solution sol;
    sol.permutation(data);
    return 0;
}
