#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: int solution(int size, vector<int>& arr){
                if(size == 1)
                    return arr[0];
                int maxElement = arr[0];
                for(int i=1;i<size;i++){
                    int sum = arr[i] + arr[i-1];
                    if(sum > arr[i]){
                        arr[i] = sum;
                    }

                    if(maxElement < arr[i])
                        maxElement = arr[i];
                }
                return maxElement;
    }
};
int main(){
    int arraySize; cin>>arraySize;
    vector<int> arr;
    for(int i = 0 ;i<arraySize;i++){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    cout<<sol.solution(arraySize,arr);
    return 0;
}
