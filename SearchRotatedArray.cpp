#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: int binarySearch(vector<int>& nums, int target, int start, int end){
                if(start >= end)
                     return -1;
                int mid = (start + end) /2 ;
                if(nums[mid] == target)
                    return mid;
                if(nums[start] == target)
                    return start;
                if(nums[end] == target)
                    return end;
                if(nums[mid] < target)
                    return binarySearch(nums,target,mid+1,end);
                else 
                    return binarySearch(nums,target,start+1,mid);
             }
    public: int search(vector<int>& nums, int target){
                int last = nums.size() - 1;
                if(last == 0){
                    if(nums[last] == target)
                        return 0;
                    else
                        return -1;
                }
                int start = 0; 
                int mid = (start + last)/2;

                for(mid;mid<=last;mid++){
                    if(nums[mid] < nums[last]){
                        if(nums[mid] <= target && target <= nums[last]){
                            return binarySearch(nums,target,mid,last);
                        }
                        break;
                    }
                }
                mid--;
                for(start;start<=mid;mid--){
                    if(nums[start] < nums[mid]){
                        if(nums[start] <= target && target <= nums[mid]){
                            return binarySearch(nums,target,start,mid);
                        }
                        break;
                    }
                }
                return -1;
            }
};

int main(){
    int size; cin>>size;
    vector<int> nums;
    while (--size) {
       int tmp; cin>>tmp; 
       nums.push_back(tmp);
    }
    int target; cin>>target;
    Solution sl;
    cout<<sl.search(nums,target);
    return 0;
}
