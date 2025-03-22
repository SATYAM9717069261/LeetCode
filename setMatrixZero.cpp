#include<bits/stdc++.h>
using namespace std;
void print(vector<vector<int>> arr){
    cout<<endl;
    cout<<" ================================ "<<endl;
    for(vector<int> i: arr){
        for(int j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
class Solution {
    public: void setZeroes(vector<vector<int>>& matrix) {
                int m = matrix.size();
                int n = matrix[0].size();
                vector<pair<int,int>> pos;

                cout<<"m+>"<<m<<endl;

                cout<<"n+>"<<n<<endl;
                for(int i=0;i<m;i++){
                    for(int j=0;j<n;j++){
                        if(matrix[i][j] == 0){
                            pos.push_back({i,j});
                        }
                    }
                }

                for(pair<int,int> p : pos){
                    int i = p.first;
                    int j = p.second;
                    for(int k=0;k<n;k++){
                        matrix[i][k] = 0;
                    }
                    for(int k=0;k<m;k++){
                        matrix[k][j] = 0;
                    }


                }
                print(matrix);
            }
};
int main(){
  int n; cin>>n;
  int m; cin>>m;
  vector<vector<int>> arr;
  for(int i=0;i<m;i++){
      vector<int> tmp; 
      for(int j=0;j<n;j++){
          int dum; cin>>dum;
          tmp.push_back(dum);
      }
      arr.push_back(tmp);
  }
  Solution sol;
  sol.setZeroes(arr);
  return 0;
}
