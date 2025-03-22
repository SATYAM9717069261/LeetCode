#include<bits/stdc++.h>
using namespace std;
class Solution{
    public: vector<vector<int>> intersection(vector<vector<int>> arr1, vector<vector<int>> arr2){
                int arr1len = arr1.size();
                int arr2len = arr2.size();
                vector<vector<int>> result;
                for(int i=0,j=0; i<arr1len && j<arr2len;){
                    int start = max(arr1[i][0],arr2[j][0]);
                    int end = min(arr1[i][1],arr2[j][1]);
                    if(end>=start)
                        result.push_back({start,end});
                   if(arr1[i][1]<arr2[j][1])
                       i++;
                   else
                       j++;
                }
                return result;
            }
};

int main(){
    int len1; cin>>len1;
    int len2; cin>>len2;
    vector<vector<int>> arr1;
    vector<vector<int>> arr2;

    while(len1--){
        int start; cin>>start;
        int end; cin>>end; 
        arr1.push_back({start,end});
    }


    while(len2--){
        int start; cin>>start;
        int end; cin>>end; 
        arr2.push_back({start,end});
    }
    Solution sol;
    for(auto i:sol.intersection(arr1,arr2)){
        cout<<i[0]<<" "<<i[1]<<endl;
    }
//sol.intersection(arr1,arr2)
    return 0;
}

