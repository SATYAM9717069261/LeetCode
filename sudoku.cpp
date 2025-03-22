#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<char>>& board){
    for(int i=0; i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}

class Solution {
    private:
        vector<int> minMax(int x){
            int i, i_max;
            if(x<3){
                i=0; i_max = 3;
            }else if(x<6){
                i=3; i_max = 6;
            }else{
                i=6; i_max = 9;
            }
            return {i,i_max};
        }
        bool check(vector<vector<char>>& arr, int i, int j){
            char num = arr[i][j];
            for(int k=0;k<9;k++){
                if((k!=j && arr[i][k] == num) || ( i!=k && arr[k][j] == num))
                    return false;
            }
            vector<int>start_i = minMax(i);
            vector<int>start_j = minMax(j);
            for(int k=start_i[0];k<start_i[1];k++){
                for(int l = start_j[0];l<start_j[1];l++){
                    if( i!=k && j!=l && arr[k][l] == num )
                        return false;
                }
            }
            return true;
        }
        bool compute(vector<vector<char>>& arr, int i, int j){
            if(i == 8 && j == 8){
                for(int k=1;k<=9;k++){
                    arr[i][j]='0' + k;
                    if(check(arr,i,j))
                        return true;
                }
                return false;
            }
            if(arr[i][j] != '.'){
                if(i<8)
                    return compute(arr,i+1,j);
                else 
                    return compute(arr,0,j+1);
            }
            for(int k=1;k<=9;k++){
                arr[i][j]='0' + k;
                if(check(arr,i,j)){
                    bool status;
                    if(i<8)
                        status = compute(arr,i+1,j);
                    else
                        status = compute(arr,0,j+1);

                    if(status)
                        return true;
                }
            }
            arr[i][j] = '.';
            return false;
        }
    public: void solveSudoku(vector<vector<char>>& board) {
                compute(board,0,0);
        }
};

int main(){
    vector<vector<char>> sudo;
    for(int i=0;i<9;i++){
        vector<char> tmp;
        for(int j=0;j<9;j++){
            char tmpChar; cin>>tmpChar;
            tmp.push_back(tmpChar);
        }
        sudo.push_back(tmp);
    }
    Solution sol;
    sol.solveSudoku(sudo);
    print(sudo);
    return 0;
}
