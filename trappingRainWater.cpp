#include<bits/stdc++.h>
using namespace std;
class Solution {
    public: int trap(vector<int>& arr) {
                int len = arr.size();
                if (len < 3) return 0;  // Early return for cases where trapping is not possible
                int left = 0, right = len - 1;
                int leftMax = 0, rightMax = 0;
                int sum = 0;

                while (left <= right) {
                    if (arr[left] <= arr[right]) {
                        if (arr[left] >= leftMax) {
                            leftMax = arr[left];
                        } else {
                            sum += leftMax - arr[left];
                        }
                        left++;
                    } else {
                        if (arr[right] >= rightMax) {
                            rightMax = arr[right];
                        } else {
                            sum += rightMax - arr[right];
                        }
                        right--;
                    }
                }
                return sum;
            }
};
int main(){
    vector<int> arr;
    int size; cin>>size;
    while(size--){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    sol.trap(arr);
    return 0;
}
