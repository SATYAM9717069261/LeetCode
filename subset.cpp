#include<bits/stdc++.h>
using namespace std;
void print(set<vector<int>> arr){
    for(vector<int> i : arr){
        for(int j:i){
            cout<<j<<" ";
        }
        cout<<endl;
    }

}
class Solution {
    private:void findSubset(vector<int>& arr,int current,set<vector<int>>& ans,vector<int>& tmp){
                   if(current == arr.size()){
                       ans.insert(tmp);
                       return;
                   }
                   for(int i=current ;i<arr.size();i++){
                       tmp.push_back(arr[i]);
                       ans.insert(tmp);
                      findSubset(arr,i+1,ans,tmp);
                      tmp.pop_back();
                   }
             }
    public: vector<vector<int>> subsetsWithDup(vector<int>& arr) {
                sort(arr.begin(),arr.end());

                set<vector<int>> ans;
                int size = arr.size();
                for(int i=0;i<size;i++){
                    vector<int> tmp;
                    tmp.push_back(arr[i]);
                    ans.insert(tmp);
                    findSubset(arr,i+1,ans,tmp);
                    tmp.pop_back();
                }
                vector<vector<int>> res;
                for(vector<int> i: ans)
                    res.push_back(i);
                print(ans);

                return res;
        }
};
int main(){
    int num; cin>>num;
    vector<int> arr;
    for(int i=0;i<num;i++){
        int tmp; cin>>tmp;
        arr.push_back(tmp);
    }
    Solution sol;
    sol.subsetsWithDup(arr);
    return 0;
}
