#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void printSingle(vector<int>& arr){
                 for(int j: arr){
                     cout<<j<<" ";
                 }
                 cout<<endl;
             } 
             void print(vector<vector<int>>& arr){
                 for(vector<int> i: arr){
                     for(int j: i){
                         cout<<j<<" ";
                     }
                     cout<<endl;
                 }
             }
        void ans(vector<int>& arr,vector<vector<int>>& result, int target, int sum=0,int start = 0,vector<int>subResult = vector<int>{}){
                if(sum == target){
                    result.push_back(subResult);
                    return;
                }
                if(sum > target)
                    return;
                
                for(int i=start;i<arr.size();i++){
                    if(sum<= target){
                        subResult.push_back(arr[i]);
                    }
                    ans(arr,result,target,sum+arr[i],i,subResult);
                    subResult.pop_back();
                }
                return;
             }
    public: vector<vector<int>> combination(vector<int>& candidate, int target){
                vector<vector<int>> result;
                ans(candidate,result,target);
                return result;
            }
};

int main(){
    int size; cin>>size;
    vector<int> candidate;
    while(size--){
        int temp; cin>>temp;
        candidate.push_back(temp);
    }
    int target; cin>>target;
    Solution sol;
    vector<vector<int>> ans;
    ans = sol.combination(candidate,target);
    for(vector<int> i: ans){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
