#include<bits/stdc++.h>
using namespace std;
class Solution {
  public: string solution(vector<int>& arr, int res){
            set<int> topics(arr.begin(),arr.end());
            if(topics.size() < res)
              return "Yes";
            return "No";
          }
};

int main(){
    int test; cin>>test;
    while (test--) {
        int num; cin>>num;
        int res; cin>>res;
        vector<int> arr(num,0);
        for(int i=0;i<num;i++)
            cin>>arr[i];
        Solution sol;
       cout<<sol.solution(arr,res)<<endl;
    }
    return 0;
}
