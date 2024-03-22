#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void printSingle(vector<int>& arr){
                 for(int j: arr){
                     cout<<j<<" ";
                 }
                 cout<<endl;
             } 
             void print(set<vector<int>>& arr){
                 for(vector<int> i: arr){
                     for(int j: i){
                         cout<<j<<" ";
                     }
                     cout<<endl;
                 }
             }
        
        void ans2(vector<int>& arr,set<vector<int>>& result, int target, int sum=0,int start = 0,vector<int>subResult = vector<int>{}){
            int arrSize = arr.size();
            cout<<" START =>"<<start << " , "<<arrSize<<endl;
            if(start > arrSize || sum > target)
                return;
            if(sum == target){
                result.insert(subResult);
                return;
            }

            for(int i=start;i<arrSize;i++){
                int tmpSum = arr[i]+sum;
                if(tmpSum > target)
                    continue;
                subResult.push_back(arr[i]);
                while(i<arrSize && arr[i] != arr[i++]);

                ans2(arr,result,target,sum+arr[i],i+1,subResult);
                subResult.pop_back();
            }
            return;
        }
    public: set<vector<int>> combination(vector<int>& candidate, int target){
                set<vector<int>> result;
                printSingle(candidate);
                sort(candidate.begin(),candidate.end());
                ans2(candidate,result,target);
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
    set<vector<int>> ans;
    ans = sol.combination(candidate,target);
    for(vector<int> i: ans){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}
