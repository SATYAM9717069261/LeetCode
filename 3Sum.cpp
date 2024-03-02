#include<bits/stdc++.h>
using namespace std;
class Solution{
    private: void print(vector<vector<int>> arr){
                 for(vector<int> i: arr){
                    for(int j : i)
                         cout<<j <<" ";
                    cout<<endl;
                 }
            }
    public: vector<vector<int>> solution(vector<int>& num){
                vector<vector<int>> ans;
                sort(num.begin(),num.end());
                int size = num.size();
                for(int i = 0;i <size;i++){
                    if( i > 0 && num[i] == num[i-1])
                        continue;
                    int j = i+1;
                    int k = size - 1;
                    while (j<k) {
                       int sum = num[i] + num[j] + num[k];
                       cout<<" SUM => "<<sum<<endl;
                       if(sum < 0)
                           j++;
                       else if(sum > 0)
                           k--;
                       else{
                           ans.push_back({num[i],num[j],num[k]});
                           j++;
                           k--;
                           while(j < k && num[j] == num[j-1]) j++;
                           while(j < k && num[k] == num[k+1]) k--;
                       }
                    }
                }
                Solution::print(ans);
                return {{1,0},{1,0}};
            }
};

int main(){
    int size; cin>>size;
    vector<int> num;
    for(int i=0;i<size;i++){
        int inp; cin>>inp;
        num.push_back(inp);
    }
    Solution sol;
    sol.solution(num);
    return 0;
}
