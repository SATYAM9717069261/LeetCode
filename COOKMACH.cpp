#include<bits/stdc++.h>
using namespace std;

pair<int,int> solution(vector<int>& arr, int k, int n){
    sort(arr.begin(),arr.end());
    int minDiff = INT_MAX;
    int count = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int currDiff = abs(arr[i]+arr[j]-k);
            if(currDiff < minDiff){
                minDiff = currDiff;
                count=1;
            }else if (currDiff == minDiff) {
                count++;
            }
        }
    }
    return {minDiff,count};
}
int main(){
    int test; cin>>test;
    while(test--){
        int n,k; cin>>n>>k;
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
            cin>>arr[i];
       pair<int,int> ans =  solution(arr,k,n);
       cout<<ans.first<<" "<<ans.second<<endl;
    }
    return 0;
}
