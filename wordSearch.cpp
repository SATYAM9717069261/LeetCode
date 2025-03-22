#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<bool>> arr){
    for(vector<bool>i: arr){
        for(bool j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}

void print(vector<vector<char>> arr){
    for(vector<char>i: arr){
        for(char j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}
class Solution {
    private: bool solution(vector<vector<char>>& board, string word,vector<vector<bool>>& visit,int x, int y, int current){
                 cout<<" Next Search =>"<<word[current]<<endl;
                 if(current >= word.length()){
                     return true;
                 }
                 char f_char = word[current];

                 if(x-1 > -1 && visit[x-1][y] == false && board[x-1][y] == f_char){
                     visit[x-1][y] = true;
                     if(solution(board,word,visit,x-1,y,current+1))
                         return true;
                     else
                         visit[x-1][y] = false;
                 }

                 if(x+1 < board.size()  && visit[x+1][y] == false && board[x+1][y] == f_char){
                     visit[x+1][y] = true;
                     if(solution(board,word,visit,x+1,y,current+1))
                         return true;
                     else
                         visit[x+1][y] = false;
                 }

                 if(y+1 < board[0].size()  && visit[x][y+1] == false && board[x][y+1] == f_char){

                     visit[x][y+1] = true;
                     if(solution(board,word,visit,x,y+1,current+1))
                         return true;
                     else
                         visit[x][y+1] = false;

                 }

                 if(y-1 > -1  && visit[x][y-1] == false && board[x][y-1] == f_char){

                     visit[x][y-1] = true;
                     if(solution(board,word,visit,x,y-1,current+1))
                         return true;
                     else
                         visit[x][y-1] = false;
                 }
                 cout<<" Not Found =>"<<word[current]<<endl;
                 return false;
             }

    public: bool exist(vector<vector<char>>& board, string word) {
                vector<vector<bool>> visit; 
                for(int i=0;i<board.size();i++){
                    vector<bool> tmp;
                    for(int j=0;j<board[0].size();j++){
                        tmp.push_back(0);
                    }
                    visit.push_back(tmp);
                }

                for(int i=0;i<board.size();i++){
                    for(int j=0;j<board[0].size();j++){
                        if(board[i][j] == word[0]){
                            cout<<" check =>"<<board[i][j] <<" "<<word[0]<<endl;
                            visit[i][j] = true;
                            if(solution(board,word,visit,i,j,1)){
                                cout<<" ================================= FOUND ";
                                return true;
                            }else{
                                visit[i][j] = false;
                            }
                        }
                    }
                }

                cout<<" VISIST =>"<<endl;
                print(visit);
                return false;
            }
};

int main(){
    int row; cin>>row;
    int col; cin>>col;
    vector<vector<char>> inp;
    for(int i=0;i<row;i++){
        vector<char> dummy;
        for(int j=0;j<col;j++){
            char tmp; cin>>tmp;
            dummy.push_back(tmp);
        }
        inp.push_back(dummy);
    }
    string word; cin>>word;
    Solution sol;
    //print(inp);
    sol.exist(inp,word);
    return 0;
}
