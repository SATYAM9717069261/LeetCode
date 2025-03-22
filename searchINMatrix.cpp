#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: int search(vector<vector<int>>& arr, int tar, int start, int end){
                 if(arr[start][0] == tar)
                     return start;
                 if(arr[end][0] == tar)
                     return end;

                 if( abs(start-end) < 2){
                     if(arr[end][0] < tar)
                         return end;
                     return start;
                 }else{
                     int mid = (end + start)/2 + (end+start)%2;
                     if(arr[mid][0] == tar)
                         return mid;

                     if(tar < arr[mid][0]){
                         return search(arr,tar,start,mid);
                     }else{
                         return search(arr,tar,mid,end);
                     }
                 }
                 return end;
             }

             bool searchY(vector<vector<int>>& arr, int tar, int start, int end,int x){
                 cout<<" found =>"<< (arr[x][start])<<" =>"  << (arr[x][end]);
                 if(abs(start-end) < 2){
                     return (arr[x][start]  == tar) || (arr[x][end]  == tar);
                 }else{
                     int mid = (end + start)/2 + (end + start)%2;
                     if(tar < arr[x][mid]){
                         return searchY(arr,tar,start,mid,x);
                     }else{
                         return searchY(arr,tar,mid,end,x);
                     }
                 }
                 return false;
             }

    public: bool searchMatrix(vector<vector<int>>& matrix, int target) {
                int x = search(matrix,target,0,matrix.size()-1);
                int y = searchY(matrix,target,0,matrix[0].size()-1,x);

                cout<<" X+>"<<x<<" y =>"<<y;
                return 0;
            }
};
int main(){
    int n; cin>>n;
    int m; cin>>m;
    vector<vector<int>> arr;
    for(int i=0;i<n;i++){
        vector<int> tmp;
        for(int j=0;j<m;j++){
            int num; cin>>num;
            tmp.push_back(num);
        }
        arr.push_back(tmp);
    }
    int target ; cin>>target;
    Solution sol;
    sol.searchMatrix(arr,target);
    return 0;
}
