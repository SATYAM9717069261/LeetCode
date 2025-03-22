#include<bits/stdc++.h>
using namespace std;
class Solution {

    private: void comp(vector<vector<int>>& edges, int distanceThreshold,bool[] visit){
                 if(distanceThreshold < 1 )
                     return ;

             }
    public: int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
                bool visit[100] = {false};
                vector<vector<int>> dis;   // 0->1,2
                vector<vector<int>> mat(n,vector<int>(n,0));
                 
                for(vector<int> i : edges){
                   int x = i[0]; 
                   int y = i[1];
                   int d = i[2];
                   mat[x][y] = d;
                   mat[y][x] = d;

                }

            }
};

int main(){
    int num; cin>>num;
    vector<vector<int>> edg;
    while(num--){
       int from; cin>>from;
       int to; cin>>to;
       int weight; cin>>weight;
       edg.push_back({from,to,weight});
    }
    int thres; cin>>thres;
    Solution sol;
    sol.findTheCity(edg,thres);
    return 0;
}
