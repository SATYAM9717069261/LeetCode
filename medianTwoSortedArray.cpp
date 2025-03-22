#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: double median(vector<int>& arr1, vector<int>& arr2){
                int arr1Len = arr1.size();
        int arr2Len = arr2.size();
        int totalSize = arr1Len + arr2Len;

        if (totalSize == 0) return 0.0; // handle empty input case

        // Helper lambda to get the kth element
        auto getKthElement = [&](int k) {
            int index1 = 0, index2 = 0;
            while (true) {
                // If one array is exhausted
                if (index1 == arr1Len) return arr2[index2 + k - 1];
                if (index2 == arr2Len) return arr1[index1 + k - 1];

                // If k is 1, return the minimum of the first elements
                if (k == 1) return std::min(arr1[index1], arr2[index2]);

                // Calculate new indices to compare
                int newIndex1 = std::min(index1 + k / 2 - 1, arr1Len - 1);
                int newIndex2 = std::min(index2 + k / 2 - 1, arr2Len - 1);
                int pivot1 = arr1[newIndex1];
                int pivot2 = arr2[newIndex2];

                if (pivot1 <= pivot2) {
                    k -= (newIndex1 - index1 + 1);
                    index1 = newIndex1 + 1;
                } else {
                    k -= (newIndex2 - index2 + 1);
                    index2 = newIndex2 + 1;
                }
            }
        };

        if (totalSize % 2 == 1) {
            return getKthElement(totalSize / 2 + 1);
        } else {
            return (getKthElement(totalSize / 2) + getKthElement(totalSize / 2 + 1)) / 2.0;
        }
    }
};

int main(){
    int arr1Size; cin>>arr1Size;
    int arr2Size; cin>>arr2Size;
    vector<int> arr1;
    vector<int> arr2;

    while(arr1Size--){
        int tmp; cin>>tmp;
        arr1.push_back(tmp);
    }


    while(arr2Size--){
        int tmp; cin>>tmp;
        arr2.push_back(tmp);
    }

    Solution sol;
    cout<<sol.median(arr1,arr2);
    return 0;
}
