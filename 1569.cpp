#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: vector<pair<int,int>> layout(vector<pair<int,int>>& _pairs){
                vector<pair<int,int>> result;
                bool tmpArray[100]={false};

                for(pair<int,int> i: _pairs){
                    
                    int node1 = i.first;
                    int node2 = i.second;

                    if(tmpArray [ node1 ] == false || tmpArray [node2] == false){
                        tmpArray [ node1 ] = true;
                        tmpArray [ node2 ] = true;
                        result.push_back(i);
                    } 
                }
                return result;
            }
};
int main(){
    int nodes; cin>>nodes;
    int edges; cin>>edges;
    vector<pair<int,int>> _pairs;
    for(int i=0;i<edges;i++){
        int node1; cin>>node1;
        int node2; cin>>node2;
        _pairs.push_back({node1,node2});
    }
    Solution sol;
    for(pair<int,int> i :sol.layout(_pairs)){
        cout<<i.first<<" "<<i.second<<endl;
    } 

    return 0;
} 
