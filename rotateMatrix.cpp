#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(vector<vector<int>>& matrix){
                 for(vector<int>i: matrix){
                     for(int j: i)
                         cout<<j<<" ";
                     cout<<endl;
                 }
             }
             void swap(int& a, int& b){
                 int tmp = a;
                 a = b;
                 b = tmp;
             }
             void reverse(vector<int>& arr){
                 int size = arr.size();
                 for(int i = 0;i<(size/2);i++)
                     swap(arr[i],arr[size-i-1]);
             }
    public: void rotate(vector<vector<int>>& matrix) {
        int ySize = matrix.size();
        int xSize = matrix[0].size();
        for(int i=0;i<ySize;i++){
            for(int j =i+1;j<xSize;j++)
                swap(matrix[i][j],matrix[j][i]);
        }
        for(int i=0;i<ySize;i++){
            reverse(matrix[i]);
        }
        print(matrix);
    }
};

int main(){
    int x; cin>>x;
    int y; cin>>y;

    vector<vector<int>> arr;

    while(x--){
        vector<int> tmp;
        int tmpY = y;
        while(tmpY--){
            int num ; cin>>num;
            tmp.push_back(num);
        }
        arr.push_back(tmp);
    }
    Solution sol;
    sol.rotate(arr);
    return 0;
}
