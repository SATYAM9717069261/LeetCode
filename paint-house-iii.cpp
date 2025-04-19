#include<bits/stdc++.h>
using namespace std;
class Solution {
    private: 
        vector<vector<vector<int>>> dp;

        void print(vector<int>& houses){
                 cout<<" HOUESE =>";
                 for(int i : houses){
                     cout<<i<<" ";
                 }
                 cout<<endl;
             }
             void printCost(vector<vector<int>>& costs){
                 cout<<"< ======== COST ===== >"<<endl;
                 for(vector<int> i: costs){
                     for(int j:i){
                         cout<<j<<" ";
                     }
                     cout<<endl;
                 }
             }
             int createColorCombination(vector<int> houses, int currentCost, int position, int target,int minCost,vector<vector<int>>& cost){
                 if(position>houses.size()){
                     return INT_MAX;
                 }
int ans = currentCost;

                 for(int i=0;i<cost[position].size();i++){
                     int newCost = ans + cost[position][i];
                      
                 }
             }
    public: int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
                dp = vector<vector<vector<int>>>(m+2,vector<vector<int>>(target+1,vector<int>(n+1,-1)));
                cout<<" DP SIZE +>"<<m<<" "<<target+1 <<" "<<n+1<<endl;
                int ans = createColorCombination(houses,0,0,target-1,INT_MAX,cost);
                cout<<"FINAL ANS  =>"<<ans<<endl;
                if(ans == INT_MAX)
                    return -1;
                cout<<endl;
                return ans;
            }
};
int main(){
    int husCount ; cin>>husCount;
    vector<int> houses;
    while(husCount--){
        int tmp; cin>>tmp;
        houses.push_back(tmp); 
    }
    vector<vector<int>> cost;
    int m; cin>>m;
    int n; cin>>n;
    for(int i=0;i<m;i++){
        vector<int> tmp;
        for(int j=0;j<n;j++){
            int __tmp; cin>>__tmp;
            tmp.push_back(__tmp);
        }
        cost.push_back(tmp);
    }
    int target; cin>>target; 
    int ans; cin>>ans;
    Solution sol;
    int rtn =sol.minCost(houses,cost,m,n,target)  ;
    cout<<(rtn == ans);
    return 0;
} 


/**
 *cout<<" position =>"<<position << " TARGET =>"<<target<<endl;
 print(houses);
 if(position >= houses.size()){
 if(target == 0)
 return min(totalCost,minAns);
 return minAns;
 }
 if(target <= 0 || target>(houses.size() - position)){
 cout<<"LIMIT REACHED =>"<<minAns<<endl;
 return minAns;
 }

 int ans = minAns;
 if(houses[position]!=0){
 if(position > 0 && houses[position] != houses[position-1])
 target = target-1;
 ans = min(createColorCombination(houses,totalCost,position+1,target,ans,cost),minAns);
 }
 else{
 for(int i=0;i<cost[position].size();i++){
 houses[position] = i+1 ;  
 int newtarget = target;
 if(position > 0 && houses[position] != houses[position-1])
 newtarget = target-1;
 if(target < 0 || target>(houses.size() - position))
 return minAns;

 int newCost = totalCost + cost[position][houses[position]-1];
 cout<<" CHECK DP =>"<<position+1 << " "<<newtarget << " " <<i<<endl;
 if(dp[position+1][newtarget][i] != -1){
 cout<<" \t\t\t\t HITS =>"<<dp[position+1][newtarget][i]<<endl;
 ans = dp[position+1][newtarget][i];
 }else{
 ans = min(createColorCombination(houses,newCost,position+1, newtarget,ans,cost),minAns);
 cout<<" \t\t NEW DATA STORE "<<endl;
 print(houses);
 cout<<" KEY =>"<<position<<" "<<target << " " <<i <<" =>"<<ans<<endl;
 dp[position][target][i] = ans;
 }
 }
 }
 return ans;
 **/
