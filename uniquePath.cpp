#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> arr){
    for(vector<int> i: arr){
        for(int j : i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
class Solution {
    public: int uniquePaths(int m, int n) {
                vector<vector<int>> arr;
                for(int i=0;i<m;i++){
                    vector<int> tmp;
                    for(int j=0;j<n;j++){
                        if(i == m-1 || j == n-1){
                            tmp.push_back(1);
                        }else{
                            tmp.push_back(0);
                        }
                    }
                    arr.push_back(tmp);
                }

                for(int i = (m-2); i>=0;i--){
                    for(int j = (n-2); j>=0;j--){
                       arr[i][j] = arr[i+1][j] + arr[i][j+1]; 
                    }
                }
                print(arr);
                return 1;
        }
};
int main(){
    int m; cin>>m;
    int n; cin>>n;
    Solution sol;
    sol.uniquePaths(m,n);
    return 0;
}
