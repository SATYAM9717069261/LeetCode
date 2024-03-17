#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: int binarySearch(vector<int>& nums, int target, int start, int end) {
            if (start >= end)
                return -1;
            int mid = (start + end) / 2;
            if (nums[mid] == target)
                return mid;
            if (nums[start] == target)
                return start;
            if (nums[end] == target)
                return end;
            if (nums[mid] < target)
                return binarySearch(nums, target, mid + 1, end);
            else
                return binarySearch(nums, target, start + 1, mid);
        }

    public: vector<int> searchRange(vector<int>& nums, int target) {
            int v_size = nums.size();
            if (v_size == 1) {
                if (nums[0] == target)
                    return {0, 0};
                else
                    return {-1, -1};
            }
            int position = binarySearch(nums, target, 0, v_size-1);
            if (position == -1)
                return {-1, -1};

            int start = position;
            int end = position;
            bool startDone = false;
            bool endDone = false;
            while (true) {
                if (startDone == false && start > -1 && nums[start] == target)
                    start--;
                else
                    startDone = true;

                if (endDone == false && end <= (v_size-1) && nums[end] == target)
                    end++;
                else
                    endDone = true;

                if (startDone && endDone)
                    break;
            }
            return {start + 1, end - 1};
        }
};

int main(){
    int size; cin>>size;
    vector<int> nums;
    while (size--) {
       int tmp; cin>>tmp; 
       nums.push_back(tmp);
    }
    int target; cin>>target;
    Solution sl;
    vector<int> ans = sl.searchRange(nums,target);
    for(int i: ans)
        cout<<i<<" ";
    return 0;
}
