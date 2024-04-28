#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(vector<vector<int>>& arr){
                 for( vector<int> i : arr){
                     for(int j: i){
                         cout<<j<< " ";
                     }
                     cout<<endl;
                 }
             }
            void singleprint(vector<int>& arr){
                     for(int j: arr){
                         cout<<j<< " ";
                     }
             }
    public: vector<int> sol(vector<vector<int>>& arr){
                vector<int> ans;
                int n = arr.size();
                int m = arr[0].size();
                int left = 0, right = m-1;
                int top = 0, bottom = n-1;
                while(top <= bottom && left <= right){
                    for(int i=left;i<=right;i++)
                            ans.push_back(arr[top][i]);
                        top++;
                    for(int i=top;i<=bottom;i++)
                            ans.push_back(arr[i][right]);
                        right--;
                    if(top <= bottom ){
                        for(int i=right;i>=left;i--)
                            ans.push_back(arr[bottom][i]);
                        bottom--;
                    }
                    if(left <= right){
                        for(int i=bottom;i>=top;i--)
                            ans.push_back(arr[i][left]);
                        left++;
                    }
                }
                print(arr);
                singleprint(ans);
                return ans;
            }
};
int main(){
    int row; cin>>row;
    int col; cin>>col;
    vector<vector<int>> arr;
    for(int i=0;i<row;i++){
        vector<int> tmpCol;
        for(int j=0;j<col;j++){
            int tmp; cin>>tmp;
            tmpCol.push_back(tmp);
        }
        arr.push_back(tmpCol);
    }
    Solution solution;
    solution.sol(arr);
    return 0;
}
