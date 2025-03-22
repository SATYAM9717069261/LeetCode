#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
        bool isCycled(unordered_map<int, vector<int>>& adj, int u, vector<bool>& visited, vector<int>& result) {  // u : parent 
            /* @return isCycled : true */
            if(adj[u].size() == 0){
                cout<<" PUSH   TOP =>"<<u<<endl;
                result.push_back(u);
                return false;
            }
            if(visited[u] == true)
                return true;

            visited[u] = true;

            for(int i : adj[u]){
                if(isCycled(adj,i,visited,result))
                    return true;
            }
            cout<<" PUSH  =>"<<u<<endl;
            result.push_back(u);
            return false;
        }

    public:
        bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
           vector<bool> visited(numCourses,0); 
           unordered_map<int,vector<int>> adj;
           for(vector<int> i : prerequisites)
               adj[i[0]].push_back(i[1]);
          
           vector<int> result;
           for(int i = 0;i<numCourses;i++){
               cout<<"CALL  =>"<<i<<endl;
                if(!isCycled(adj,i,visited,result)){
                }
           }
           for(int i : result){
               cout<<i<<" ";
           }
           return false;

        }
};

int main(){
    int count; cin>>count;
    int numCou = count;
    vector<vector<int>> req;
    while(count--){
        int tmp; cin>>tmp;
        int tmpsec; cin>>tmpsec;
        vector<int> tmpvect;
        tmpvect.push_back(tmp);
        tmpvect.push_back(tmpsec);
        req.push_back(tmpvect);
    }
    Solution sol;
    sol.canFinish(numCou,req);
    return 0;
}
